#include <assert.h>
#include <string.h>
#include <deque>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

void show_func() { cout << __func__ << endl; }

// 运行时断言
void use_nobug_example() {
  // assert(1 < 0);//g++ stability_compatibility.cpp -DNDEBUG will skip this
}

// 编译时断言
void assert_while_compile() {
  // static_assert(1 < 0,"this get assert error");// this will compile failed
}

// 快速初始化成员变量
struct {
  int a = 0;
  double b{0.23};
} b;

class CQuickInit {
 public:
  CQuickInit() = default;
  CQuickInit(int a, std::string b) : m_a(a), m_str(std::move(b)) {}
  void show() const {
    cout << m_a << endl;
    cout << m_str << endl;
    cout << m_gb_ << endl;
  }

  int m_a = 1;
  std::string m_str = "default str";
  static int m_gb_;
  const static int kMKgb = 1;
};

int CQuickInit::m_gb_ = 0;

void print_struct() { cout << b.a << endl; }

void quick_init() {
  CQuickInit q1;
  q1.show();

  CQuickInit q2(3, "init list");
  q2.show();
  q2.m_gb_++;
  q1.show();
}

// c++11 sizeof
void cpp11_sizeof() {
  cout << sizeof(CQuickInit::m_str) << endl;  // 普通成员变量
  cout << sizeof(CQuickInit::m_a) << endl;
}

// 继承构造函数
class CBase {
 public:
  CBase(int a) : m_a(a) {}
  CBase(const std::string& defaultstr) : m_str(defaultstr) {}
  CBase() {}
  virtual void show() {
    cout << "int " << m_a << endl;
    cout << "string " << m_str << endl;
  }

 private:
  int m_a = 0;
  std::string m_str = "default structure";
};

// normal c98
class COldStander : public CBase {
 public:
  COldStander(int a) : CBase(a) {}
  COldStander(const std::string& oldstr) : CBase(oldstr) {}
  COldStander() {
    m_oldint = 0;
    m_oldstr = "default old";
  }

  void show() {
    cout << "old int" << m_oldint << endl;
    cout << "old str" << m_oldstr << endl;
  }

 private:
  int m_oldint;
  std::string m_oldstr;
};

// c++11 inherit 继承构造函数

class CNewStander : public CBase {
 public:
  using CBase::CBase;

 private:
  int m_newint = 10;
  std::string m_strnew = "new stander";
};

void inherit_structure() {
  COldStander old_obj;
  old_obj.show();

  CNewStander new_obj("new obj");
  new_obj.show();
}

// 委派构造函数,构造函数还要调用一些其他的公用初始化
class CConstructer {
 private:
  template <class T>
  CConstructer(T first, T last) : m_list(first, last) {
    printf("default constructer copy begin\n");
  }

  std::list<int> m_list;

 public:
  CConstructer(std::vector<int>& d) : CConstructer(d.begin(), d.end()) {}
  CConstructer(std::deque<int>& d) : CConstructer(d.begin(), d.end()) {}

  void show() { cout << "list size " << m_list.size() << endl; }
};

void delegation_constructer() {
  std::vector<int> tmp1 = {1, 2, 3};
  CConstructer oD1(tmp1);
  oD1.show();
  std::deque<int> tmp2 = {1};
  CConstructer oD2(tmp2);
  oD2.show();
}

// initializer list
class CInitialTmp {
 public:
  CInitialTmp(std::initializer_list<int> l) {
    for (auto& iteritor : l) {
      iarr.push_back(iteritor);
    }
  }

  CInitialTmp(std::initializer_list<std::pair<string, string>> l) {
    cout << "initializer list size " << l.size() << endl;
    for (auto& item : l) {
      cout << "begin insert" << endl;
      auto ret = _inital_map.insert(item);
      if (!ret.second) {
        cout << "insert failed" << endl;
      }
    }

    cout << "init map size " << _inital_map.size() << endl;
  }

  void show_vecotr() {
    cout << __func__ << " CinitialTmp show" << endl;
    for (auto& i : iarr) {
      printf("%d ", i);
    }
    cout << endl;
  }

  void show_map() {
    cout << __func__ << " CinitialTmp show" << endl;
    for (auto& i : _inital_map) {
      printf("key %s,val %s", i.first.c_str(), i.second.c_str());
    }
    cout << endl;
  }

 private:
  std::vector<int> iarr;
  std::map<string, string> _inital_map;
};
void initizlizer_list_demo() {
  std::vector<int> vectmp = {1, 2, 3, 4};
  std::map<std::string, int> omap = {{"tmp1", 123}, {"tmp2", 456}};
  for (auto& v : vectmp) {
    printf("initizlizer list %d ", v);
  }
  cout << endl;
  for (auto& v : omap) {
    printf("key %s val %d\n", v.first.c_str(), v.second);
  }
  cout << endl;

  // use initialize list
  CInitialTmp oInitTmp{1, 2, 3, 4, 5};
  oInitTmp.show_vecotr();
  CInitialTmp oInitTmpMap{{"mapkey1", "mapval1"}, {"mapkey2", "mapval2"}};
  oInitTmpMap.show_map();
}

// auto decltype
void auto_decltype_demo() {
  int i;
  decltype(i) j = 0;
  cout << __func__ << " " << typeid(j).name() << endl;
}

// 基于范围的for循环
void auto_for(const std::vector<int>& v) {
  std::vector<int> tmpv{4, 5, 6, 7, 8};
  for (auto i : tmpv) {
    printf("autofor %d\n", i);
  }

  for (auto i : v) {
    printf("auto func parm for %d\n", i);
  }
}

// 强类型枚举
void enum_demos() {
  enum class Type : char { Man, Women };
  Type t = Type ::Man;
  // 强枚举类型需要显示强制转换才能对比
  if (1 > static_cast<int>(t)) {
    cout << "Type ::Man" << endl;
  }

  // 匿名的enum 强制类型没有意义
  enum { fisrt, second, third };
  if (second == 1) {
    cout << "second == 1" << endl;
  }
}

// 智能指针
class CSmartPtrDemoObj {
 public:
  CSmartPtrDemoObj() { cout << "init " << __func__ << endl; }
  ~CSmartPtrDemoObj() { cout << "destroy " << __func__ << endl; }
  void auto_ptr_show() { cout << __func__ << endl; }

 private:
  int itmp1 = 1;
  int itmp2 = 2;
  std::string name = "hulk";
};

void auto_ptr_demos() {
  // unique_ptr
  std::unique_ptr<CSmartPtrDemoObj> uptr(new CSmartPtrDemoObj());
  uptr->auto_ptr_show();

  // std::unique_ptr<CSmartPtrDemoObj> uptr2=uptr;//通不过编译，unique_ptr不支持复制
  std::unique_ptr<CSmartPtrDemoObj> uptr2 = std::move(uptr);
  uptr2->auto_ptr_show();  // todo: ?? 理论上应该报错？
  uptr->auto_ptr_show();
  (*uptr).auto_ptr_show();

  if (uptr.get() == nullptr) {
    cout << "uptr.get()  is null" << endl;
  }

  if (uptr2.get() != nullptr) {
    cout << "uptr2.get()  is not null" << endl;
  }

  std::shared_ptr<CSmartPtrDemoObj> sptr(new CSmartPtrDemoObj());
  sptr->auto_ptr_show();

  std::shared_ptr<CSmartPtrDemoObj> sptr2 = sptr;
  sptr2.reset();

  std::weak_ptr<CSmartPtrDemoObj> wptr = sptr2;
  cout << "wptr.use_count() " << wptr.use_count() << endl;

  auto tmpfunc = [](std::weak_ptr<CSmartPtrDemoObj>& wk_ptr) {
    cout << typeid(wk_ptr).name() << endl;
    cout << "wk_ptr use_count " << wk_ptr.use_count() << endl;
    if (wk_ptr.lock() == nullptr) {
      cout << "wk_ptr.lock() == nullptr" << endl;
    } else {
      cout << "wk_ptr.lock() != nullptr" << endl;
    }
  };

  tmpfunc(wptr);

  cout << "sptr.use_count() " << sptr.use_count() << endl;
  wptr = sptr;

  tmpfunc(wptr);
}

// 右值引用
// 传统的拷贝构造，使用了临时的值
struct CNode {
  CNode(int a = 0) { node_num = a; }
  char name[1024] = "local node";
  int node_num = 0;
};

class CtmpCopySimple {
 public:
  CtmpCopySimple(std::initializer_list<CNode> l) : m_pbuff(nullptr) {
    cout << __func__ << " init " << m_iconstract++ << endl;
    m_pbuff = new CNode[buff_size];
    assert(m_pbuff);
    for (auto& v : l) {
      if (m_copoy_index >= buff_size) {
        assert(false);
      }
      m_pbuff[m_copoy_index++] = v;
    }
  }

  // 普通拷贝构造 deep copy
  CtmpCopySimple(const CtmpCopySimple& tmp) {
    cout << "copy init" << m_icopyinit++ << endl;
    m_pbuff = new CNode[buff_size];
    assert(m_pbuff);
    memset(m_pbuff, 0, buff_size * sizeof(CNode));
    memcpy(m_pbuff, tmp.m_pbuff, buff_size * sizeof(CNode));
    m_copoy_index = tmp.m_copoy_index;
  }

  // 右值引用 节省拷贝次数
  CtmpCopySimple(CtmpCopySimple&& tmp) noexcept {
    cout << "move construct " << m_imoveconstruct++ << endl;
    m_pbuff = tmp.m_pbuff;
    tmp.m_pbuff = nullptr;
    m_copoy_index = tmp.m_copoy_index;
  }

  bool PushNode(const CNode& node) {
    if (m_copoy_index >= buff_size) {
      cout << "push node size more than large" << endl;
      return false;
    }

    m_pbuff[m_copoy_index++] = node;
    return true;
  }
  void show_node() {
    cout << __func__ << " begin" << endl;
    for (int i = 0; i < m_copoy_index; i++) {
      CNode& node = m_pbuff[i];
      cout << "node num: " << node.node_num << endl;
    }
    cout << __func__ << " end" << endl;
  }

  static void clear() {
    m_iconstract = 0;
    m_idestruct = 0;
    m_icopyinit = 0;
    cout << "m_iconstract " << m_iconstract << endl;
  }
  ~CtmpCopySimple() {
    cout << __func__ << " destroy " << m_idestruct++ << endl;
    if (m_pbuff != nullptr) {
      delete[] m_pbuff;
      m_pbuff = nullptr;
    }
  }

 private:
  static int m_iconstract;      // 构造次数
  static int m_idestruct;       // 析构次数
  static int m_icopyinit;       // 拷贝构造次数
  static int m_imoveconstruct;  // 移动构造次数
 private:
  int m_copoy_index = 0;
  const int buff_size = 32;
  CNode* m_pbuff;
};

int CtmpCopySimple::m_iconstract = 0;
int CtmpCopySimple::m_idestruct = 0;
int CtmpCopySimple::m_icopyinit = 0;
int CtmpCopySimple::m_imoveconstruct = 0;

void copy_constract_demos() {
  CtmpCopySimple a{{CNode(1)}, {CNode(2)}};
  a.show_node();
  CtmpCopySimple b(a);
  b.show_node();

  CtmpCopySimple::clear();
}

CtmpCopySimple get_tmp_obj() { return CtmpCopySimple({CNode(9)}); }

void copy_constract_demos2() {
  cout << __func__ << endl;
  CtmpCopySimple tmp = get_tmp_obj();
  // CtmpCopySimple tmp2 = tmp;
  // CtmpCopySimple tmp3 = tmp2;
  tmp.show_node();
}

CtmpCopySimple return_tmp_value(int a, int b) { return CtmpCopySimple{CNode(a), CNode(b)}; }
void copy_move_construct_demos3() {
  cout << __func__ << " begin" << endl;
  // 使用右值引用，被引用的临时变量的生命周期就与ret相同了
  CtmpCopySimple&& ret = return_tmp_value(2, 3);
  ret.show_node();
  ret.PushNode(CNode(88));
  ret.show_node();

  // c++98 常量引用左值也有此效果，但是引用后的值只读
  //  CtmpCopySimple& ret2 = return_tmp_value(4,5);  非const T &引用右值编译不会通过
  const CtmpCopySimple& ret2 = return_tmp_value(4, 5);
  // ret2.show_node();     编译不过

  CtmpCopySimple ret3 = return_tmp_value(6, 7);
  ret3.show_node();
}

void copy_move_construct_dmoes4() {
  auto val = std::is_rvalue_reference<CtmpCopySimple&&>::value;
  cout << "is rval " << val << endl;

  auto is_moveable = std::is_move_constructible<CtmpCopySimple>::value;
  cout << "is_moaveabe " << is_moveable;
}

// 完美转发,作为包装函数很方便
template <typename T, typename U>
void perfect_forward(T&& val, const U& Func) {
  cout << " forwarded..." << endl;
  Func(forward<T>(val));
}

void use_perfect_forward() {
  auto runcode1 = [](int a) -> int {
    cout << "runcode1 " << a << endl;
    return a + 1;
  };

  auto runcode2 = [](CtmpCopySimple&& a) -> void {
    cout << "CtmpCopySimple runcode2 move" << endl;
    CtmpCopySimple tmpNode(a);
    tmpNode.show_node();
  };

  auto runcode3 = [](CtmpCopySimple a) -> void {
    cout << "CtmpCopySimple runcode3 move" << endl;
    CtmpCopySimple tmpNode(a);
    tmpNode.show_node();
  };

  perfect_forward(5, runcode1);
  perfect_forward(CtmpCopySimple{CNode(111), CNode(222)}, runcode2);
  perfect_forward(CtmpCopySimple{CNode(333), CNode(444)}, runcode3);
}

// pod 类型
struct trivial1 {};
struct trivial2 {
 public:
  int a;

 private:
  int b;
};

struct trivial3 {
  trivial1 tri1;
  trivial2 tri2;
};

struct trivial4 {
  trivial2 tri_arr[4];
};
struct trivial5 {
  int a;
  static int b;
};

struct notrivial1 {
  notrivial1() : a(4) {}
  int a;
};

struct notrivial2 {
  notrivial2() {}
  int b;
};

struct notrivial3 {
  trivial2 trival;
  virtual void f() = 0;
};

void pod_type_demos() {
  // 平凡的布局
  cout << std::is_trivial<trivial1>::value << endl;
  cout << std::is_trivial<trivial2>::value << endl;
  cout << std::is_trivial<trivial3>::value << endl;
  cout << std::is_trivial<trivial4>::value << endl;
  cout << std::is_trivial<trivial5>::value << endl;
  cout << std::is_trivial<notrivial1>::value << endl;
  cout << std::is_trivial<notrivial2>::value << endl;
  cout << std::is_trivial<notrivial3>::value << endl;

  // 标准布局
}

// using 代替typedef,在模板上更有优势
typedef unsigned int UINT;
using UINTTYPE = unsigned int;
template <typename T>
using MAPTYPE = std::map<T, std::string>;

void using_typedef_demos() {
  cout << __func__ << " issame" << std::is_same<UINT, UINTTYPE>::value << endl;
  MAPTYPE<int> omap;
  omap[5] = "hulk";
  omap[6] = "hulk666";
  for (auto& v : omap) {
    cout << "key " << v.first << " val " << v.second << endl;
  }
}

int main() {
  printf("is use c library %d \n", __STDC_HOSTED__);
  printf("is use standard c %d \n", __STDC__);
  show_func();

  cout << "cpluspluse version " << __cplusplus << endl;
#if __cplusplus < 201103L
#  error "should use C++ 11 implementation"
#endif

  use_nobug_example();  // run will get errror
  print_struct();

  quick_init();

  cpp11_sizeof();

  inherit_structure();

  delegation_constructer();

  initizlizer_list_demo();

  auto_decltype_demo();

  std::vector<int> vtmp = {6, 7, 8, 9};
  auto_for(vtmp);

  enum_demos();

  auto_ptr_demos();

  copy_constract_demos();

  copy_constract_demos2();

  copy_move_construct_demos3();

  copy_move_construct_dmoes4();

  use_perfect_forward();

  pod_type_demos();

  using_typedef_demos();
  return 0;
}