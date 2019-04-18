#include <iostream>
#include <assert.h>
#include <list>
#include <deque>
#include <vector>
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

//c++11 inherit 继承构造函数

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

//委派构造函数,构造函数还要调用一些其他的公用初始化
class CConstructer
{
private:
	template<class T> CConstructer(T first,T last):m_list(first,last)
	{
		printf("default constructer copy begin\n");
	}
	
	std::list<int> m_list;
public:
	CConstructer(std::vector<int>& d) : CConstructer(d.begin(), d.end()) {}
	CConstructer(std::deque<int>& d) : CConstructer(d.begin(), d.end()) {}

	void show()
	{
		cout << "list size " << m_list.size() << endl;
	}
};

void delegation_constructer()
{
	std::vector<int> tmp1 = { 1,2,3 };
	CConstructer oD1(tmp1);
	oD1.show();
	std::deque<int> tmp2 = { 1 };
	CConstructer oD2(tmp2);
	oD2.show();
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

	delegation_constructer();


	return 0;
}