#ifndef __SYNTAX_BASE_HPP__
#define __SYNTAX_BASE_HPP__


// 多文件引入重定义
//void testNormal() {
//}

class testBase {
public:
	void show() {}

	void display();
private:
	int a = 0;
};

inline void testBase::display() {
}

template<typename T>
void testTemplate(T& t) {
	T B = t;
}

inline void testInline() {
	// inline 语义测试
}

void testBase();

#endif
