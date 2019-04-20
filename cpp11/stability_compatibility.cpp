#include <iostream>
#include <assert.h>
#include <list>
#include <deque>
#include <vector>
#include <map>
#include <initializer_list>
using namespace std;

void show_func()
{
	cout << __func__ << endl;
}

//运行时断言
void use_nobug_example()
{
	//assert(1 < 0);//g++ stability_compatibility.cpp -DNDEBUG will skip this
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
	virtual void show()
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

//initializer list
class CInitialTmp{
public:
    CInitialTmp(std::initializer_list<int> l){
        for (auto& iteritor:l)
        {
            iarr.push_back(iteritor);
        }
    }

    CInitialTmp(std::initializer_list<std::pair<string,string>> l)
    {
        cout<<"initializer list size "<<l.size()<<endl;
        for(auto& item:l)
        {
            cout<<"begin insert"<<endl;
            auto ret = _inital_map.insert(item);
            if(!ret.second) {
                cout << "insert failed" << endl;
            }
        }

        cout<<"init map size "<<_inital_map.size()<<endl;
    }

    void show_vecotr()
    {
        cout<<__func__<<" CinitialTmp show"<<endl;
        for(auto&i:iarr)
        {
            printf("%d ",i);
        }
        cout<<endl;
    }

    void show_map()
    {
        cout<<__func__<<" CinitialTmp show"<<endl;
        for(auto&i:_inital_map)
        {
            printf("key %s,val %s",i.first.c_str(),i.second.c_str());
        }
        cout<<endl;
    }

private:
    std::vector<int> iarr;
    std::map<string,string> _inital_map;
};
void initizlizer_list_demo()
{
   std::vector<int> vectmp={1,2,3,4};
   std::map<std::string,int> omap={{"tmp1",123},{"tmp2",456}};
   for(auto& v:vectmp)
   {
       printf("initizlizer list %d ",v);
   }
   cout<<endl;
   for(auto& v:omap)
   {
       printf("key %s val %d\n",v.first.c_str(),v.second);
   }
   cout<<endl;

    //use initialize list
    CInitialTmp oInitTmp{1,2,3,4,5};
    oInitTmp.show_vecotr();
    CInitialTmp oInitTmpMap{{"mapkey1","mapval1"},{"mapkey2","mapval2"}};
    oInitTmpMap.show_map();
}

//auto decltype
void auto_decltype_demo()
{
    int i;
    decltype(i) j=0;
    cout<<__func__<<" "<<typeid(j).name()<<endl;
}

//基于范围的for循环
void auto_for(const std::vector<int>& v)
{
    std::vector<int> tmpv{4,5,6,7,8};
    for(auto i:tmpv)
    {
        printf("autofor %d\n",i);
    }

    for(auto i:v)
    {
        printf("auto func parm for %d\n",i);
    }
}

//强类型枚举
void enum_demos()
{
    enum class Type:char{Man,Women};
    Type t = Type ::Man;
    //强枚举类型需要显示强制转换才能对比
    if(1 > static_cast<int>(t))
    {
        cout<<"Type ::Man"<<endl;
    }

    //匿名的enum 强制类型没有意义
    enum {fisrt,second,third};
    if(second == 1)
    {
        cout<<"second == 1"<<endl;
    }
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

    initizlizer_list_demo();

    auto_decltype_demo();

    std::vector<int> vtmp={6,7,8,9};
    auto_for(vtmp);

    enum_demos();
	return 0;
}