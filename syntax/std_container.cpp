#include "std_container.hpp" 

#include <array>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <vector>
#include <sstream>
#include "utils/log.hpp"
#include "utils/log_helper.hpp"

void testBitset() {
	FUNC_TRACE;
	const std::size_t N = 64;
	std::bitset<N> myBitset;
	myBitset[0] = 1;
	myBitset[1] = 0;
	myBitset[2] = 1;
	myBitset[3] = 0;

	// log_info("size[%lu] str[%s] nun[%u]", myBitset.size(), myBitset.to_string().c_str(), myBitset.to_ulong());
	log_info("size[%lu] bytes[%d] num[%lu]", myBitset.size(), sizeof(myBitset), myBitset.to_ullong());
}

void testBitMap() {
	#define N 32 
	class BitMap {
	public:
		BitMap(int32_t size) {
			mBitData.resize(size);
			std::bitset<N> bs;
			for (int32_t i = 0; i < size; i++) {
				mBitData[i] = bs;
			}
		}

	public:
		void setData(int64_t value) {
			int32_t index = value / N;
			int32_t rowIndex = value % N;
			std::bitset<N>& bitData = mBitData[index];
			bitData[rowIndex] = 1;
		}

		void unsetData(int64_t value) {
			int32_t index = value / N;
			int32_t rowIndex = value % N;
			mBitData[index][rowIndex] = 1;
		}

		bool isExist(int64_t value) {
			int32_t index = value / N;
			int32_t rowIndex = value % N;
			return mBitData[index][rowIndex];
		}

		void print() {
			int32_t i = 0;
			for (const auto bitValue : mBitData) {
				log_info("Index[%d] bit[%u]", i++, bitValue.to_ulong());
			}
		}

	private:
		std::vector<std::bitset<N>> mBitData;
	};
	FUNC_TRACE;

	BitMap bitMap(100);
	for (int64_t i = 0; i < 655; i++) {
		bitMap.setData(i);
	}

	bitMap.print();
}

void testList() {
	FUNC_TRACE;
	std::list<int32_t> dataList = {7,8,9,10,11};
	dataList.push_front(25);
	dataList.push_back(3);

	auto listPrint = [](const std::list<int32_t>& dataList) {
		std::ostringstream oss;
		bool first = false;
		for (const auto value : dataList) {
			if (!first) {
				first = true;
			} else {
				oss << ",";
			}
			oss << value;
		}
		log_info("List[%s]", oss.str().c_str());
	};

	listPrint(dataList);
	dataList.sort();
	listPrint(dataList);
	dataList.pop_back();
	dataList.pop_front();
	listPrint(dataList);
}

void testVector() {
	FUNC_TRACE;
	std::vector<int32_t> dataVec = {1,2,3,4,5};
	dataVec.push_back(6);
	dataVec.push_back(7);
	dataVec.push_back(8);
	dataVec.push_back(9);
	dataVec.push_back(10);

	for(auto iter = dataVec.begin(); iter != dataVec.end();) {
		if (*iter == 7) {
			iter = dataVec.erase(iter);
		} else {
			iter++;
		}
	}

	dataVec.insert(dataVec.begin()+3, 15);
	dataVec.pop_back();
}

void testDeque() {
	FUNC_TRACE;
	std::deque<int32_t> dataDeque = {1,2,3,4,5};
	dataDeque.push_back(6);
	dataDeque.push_back(7);
	dataDeque.push_back(8);
	dataDeque.push_back(9);
	dataDeque.push_front(10);

	auto duquePrint = [](const std::deque<int32_t>& dataDeque) {
		std::ostringstream oss;
		bool first = false;
		for (const auto value : dataDeque) {
			if (!first) {
				first = true;
			} else {
				oss << ",";
			}
			oss << value;
		}
		log_info("Deque[%s]", oss.str().c_str());
	};

	duquePrint(dataDeque);

	dataDeque.pop_back();
	dataDeque.pop_front();
	
	duquePrint(dataDeque);

	log_info("Deque[2:%d] ",dataDeque[2]);
}

void testContainer() {
	FUNC_TRACE;
	testList();
	testVector();
	testDeque();
	testBitset();
//	testBitMap();
}

