#include "utils/log.hpp"
#include "utils/log_helper.hpp"
#include "algorithm/list.hpp"
#include "algorithm/tree.hpp"
#include "syntax/const.hpp"
#include "syntax/error.hpp"
#include "syntax/mutex.hpp"
#include "syntax/std_container.hpp"
#include "syntax/base.hpp"

// 初始化函数
static void init() {
	TimeHelper::init();
	Logger::init();
}

int main() {
	init();

	//基础函数测试
	testBase();

	// 模板重定义测试
//	int b = 0;
//	testTemplate(b);

	//链表基础测试 
	//listTest();

	//树测试
	//testTree();	

	//标准库容器测试
   	//testContainer();	

	//自旋锁测试
	//testSpinlock();	

	//互斥锁测试
	//testMutex();
	
	//可重入锁测试
	//testRecursiveMutex();
	
	//const语法测试
	//testConst();
	
	//异常语法测试
	//testException();
	
	//运行期断言测试
	//testAssert();
	
	//编译期断言
	//testStaticAssert();
	return 0;
}


