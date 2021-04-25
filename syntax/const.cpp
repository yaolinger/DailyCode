#include "const.hpp"

#include "utils/log.hpp"
#include "utils/log_helper.hpp"

void testConst() {
	FUNC_TRACE; 
	{
		const int constData = 1;
		int* pConstData = const_cast<int*>(&constData);
		*pConstData = 2;
		log_info("Addr[%u:%p] const addr[%u:%p]", *pConstData, pConstData, constData, &constData);
	}

	{
		class data {
		public:
			data() : mB(2) {
				mA = 1;
				//mB = 2; const 修饰必须在构造函数的初始化列表里 initialized
			} 

			void print() const {
				log_info("a[%d], b[%d]", mA, mB);
				// mA = 1; 只读不写
			}

			void changeA(int a) {
				mA = a;
			}

		private:
			int mA;
			const int mB;
		};
		data testA;
		testA.print();
		const data testB;
		// testB.changeA(3);
	}

	{
		int a  = 3;
		int b = 2;
		const int* p = &a;
		p = &b;
		// *p = 3; 无法改变地址的数据
		log_info("p[%d:%p]", *p, p);
		int* const q = &a;
		//q = &b; 无法改变p的指向
	}
}

