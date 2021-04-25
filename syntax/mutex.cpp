#include "mutex.hpp"

#include <chrono>
#include <mutex>
#include <functional>
#include <thread>
#include <pthread.h>
#include "utils/log.hpp"
#include "utils/log_helper.hpp"

// 自旋锁封装
class MySpinLock {
public:
	MySpinLock() {
		 pthread_spin_init(&mSpinMutex, 0);	
	}
    ~MySpinLock() {
		pthread_spin_destroy(&mSpinMutex);
	}

	void lock() {
		pthread_spin_lock(&mSpinMutex);
	}

	void unlock() {
		pthread_spin_unlock(&mSpinMutex);
	}

private:
	pthread_spinlock_t  mSpinMutex;
};

void testSpinlock() {
	FUNC_TRACE;
	MySpinLock spinMutex;
	int i = 0;
	auto threadFunc = [&spinMutex, &i]() {
		while (i < 900000000) {
			std::lock_guard<MySpinLock> lk(spinMutex);
			i++;
		}
	};
	std::thread th1(threadFunc);
	std::thread th2(threadFunc);
	
	th1.join();
	th2.join();
}

void testMutex() {
	FUNC_TRACE;
	std::mutex mutex;
	int i = 0;
	auto threadFunc = [&mutex, &i]() {
		while (i < 900000000) {
			std::lock_guard<std::mutex> lk(mutex);
			i++;
		}
	};
	std::thread th1(threadFunc);
	std::thread th2(threadFunc);
	
	th1.join();
	th2.join();
}

void testRecursiveMutex() {
 	FUNC_TRACE;
 	std::recursive_mutex rmutex;  // 必须原线程解锁(其他线程解锁无效) 
//	{
//		auto lockFunc = [&rmutex]() {
//			int i = 0;
//			while(i < 5) {
//				rmutex.lock();
//				log_info("线程1尝试加锁");
//				std::this_thread::sleep_for(std::chrono::seconds(5));
//				rmutex.unlock();
//				std::this_thread::sleep_for(std::chrono::seconds(1));
//				log_info("线程1解锁");
//				i++;
//			}
//			
//		};
//		auto unlockFunc = [&rmutex]() {
//			while(1) {
//				rmutex.unlock();
//				log_info("线程2尝试解锁");
//				std::this_thread::sleep_for(std::chrono::seconds(3));
//				log_info("线程2加锁");
//				std::lock_guard<std::recursive_mutex> lk(rmutex);
//			}
//		};
//		std::thread th1(lockFunc);
//		std::thread th2(unlockFunc);
//		th1.join();
//		th2.join();
//	}
 	int i = 0;
	auto threadFunc = [&rmutex, &i] {
		while (i < 900000000) {
			std::lock_guard<std::recursive_mutex> lk(rmutex);
			i++;
			std::lock_guard<std::recursive_mutex> lk2(rmutex);
			i++;
		}
	};
 	auto threadFunc2 = [&rmutex, &i] {
		while (i < 900000000) {
			std::lock_guard<std::recursive_mutex> lk(rmutex);
			i++;
		}
	};
	std::thread th1(threadFunc);
	std::thread th2(threadFunc2);
	
	th1.join();
	th2.join();
 }
