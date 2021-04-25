#include "base.hpp"

#include "utils/log.hpp"
#include "utils/log_helper.hpp"

void testBase() {
	FUNC_TRACE; 
	testInline();
//	testNormal();
	int a = 3;
	testTemplate(a);
}

