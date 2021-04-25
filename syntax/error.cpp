#include "error.hpp"

#include <assert.h>
#include <vector>
#include <exception>
#include "utils/log.hpp"
#include "utils/log_helper.hpp"

void testException() {
    try {
		//throw std::domain_error("自定义错误");
		std::vector<int> vec;
		int b = vec.at(3);
	} catch(const std::exception& e) {
		log_info("e.what[%s]", e.what());
	}
}

void testAssert() {
	int a = 0;
	assert(a != 0);	
	// 抛出abort信号
}

void testStaticAssert() {
	typedef int8_t byte;
	typedef int16_t byte2;

	decltype(byte(0)) a;
	//std::string str;
	//int a = ((str = "66666"), 2);
	//log_info("a[%d], str[%s]", a, str.c_str());

	//static_assert(1 == 2, "哎呀");
}


