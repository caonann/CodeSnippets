#include <iostream>
#include <assert.h>
using namespace std;

void show_func()
{
	cout << __func__ << endl;
}

//运行时断言
void use_nobug_example()
{
	assert(1 < 0);//g++ stability_compatibility.cpp -DNDEBUG will skip this
}

//编译时断言
void assert_while_compile()
{
	//static_assert(1 < 0,"this get assert error");// this will compile failed
}

//快速初始化成员变量
struct {
	int a = 0;
	double b{ 0.23 };
} b;

class CQuickInit
{
public:
	CQuickInit(){}
	CQuickInit(int a, const std::string& b) :m_a(a), m_str(b) {}
	void show()
	{
		cout << m_a << endl;
		cout << m_str << endl;
		cout << m_gb << endl;
	}
public:
	int m_a = 1;
	std::string m_str = "default str";
	static int m_gb ;
	const static int m_kgb = 1;
};

int CQuickInit::m_gb = 0;

void print_struct()
{
	cout << b.a << endl;
}

void quick_init()
{
	CQuickInit q1;
	q1.show();

	CQuickInit q2(3, "init list");
	q2.show();
	q2.m_gb++;
	q1.show();
}

//c++11 sizeof
void cpp11_sizeof()
{
	cout << sizeof(CQuickInit::m_str) << endl;		//普通成员变量
	cout << sizeof(CQuickInit::m_a) << endl;
}

//继承构造函数
class CBase
{
public:
	CBase(int a):m_a(a){}
	CBase(const std::string& defaultstr):m_str(defaultstr){}
	CBase(){}
	void show()
	{
		cout << "int " << m_a << endl;
		cout << "string " << m_str << endl;
	}
private:
	int m_a = 0;
	std::string m_str = "default structure";
};

//normal c98
class COldStander :public CBase
{
public:
	COldStander(int a) :CBase(a) {}
	COldStander(const std::string& oldstr):CBase(oldstr){}
	COldStander()
	{
		m_oldint = 0;
		m_oldstr = "default old";
	}

	void show()
	{
		cout << "old int" << m_oldint << endl;
		cout << "old str" << m_oldstr << endl;
	}
private:
	int m_oldint;
	std::string m_oldstr;
};

//c++11 inherit

class CNewStander :public CBase
{
public:
	using CBase::CBase;
private:
	int m_newint = 10;
	std::string m_strnew = "new stander";
};

void inherit_structure()
{
	COldStander old_obj;
	old_obj.show();

	CNewStander new_obj("new obj");
	new_obj.show();
}

int main()
{
	printf("is use c library %d \n", __STDC_HOSTED__);
	printf("is use standard c %d \n", __STDC__);
	show_func();

	cout << "cpluspluse version " << __cplusplus << endl;
#if __cplusplus < 201103L 
	#error "should use C++ 11 implementation" 
#endif
	
	use_nobug_example(); // run will get errror
	print_struct();

	quick_init();

	cpp11_sizeof();

	inherit_structure();
	return 0;
}