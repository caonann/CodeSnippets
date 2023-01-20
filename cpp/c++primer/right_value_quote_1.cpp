#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;
class HugeMem {
 public:
  HugeMem(int size) : sz(size > 0 ? size : 1) { c = new int[size]; }
  ~HugeMem() { delete[] c; }
  HugeMem(HugeMem&& hm) : sz(hm.sz), c(hm.c) {
    cout << "rval copy constructed" << endl;
    hm.c = nullptr;
  }
  HugeMem(const HugeMem& hm) : sz(hm.sz) {
    cout << "lval copy constructed" << endl;
    c = new int[sz];
    memcpy(c, hm.c, sz * sizeof(int));
    printf("sizeof int %ld\n", sizeof(int));
    printf("sizeof c %ld\n", sizeof(c));
  }

  int get_data(int index) { return c[index]; }

  int* c;
  int sz;
};

class MoveAble {
 public:
  MoveAble() : i(new int(3)), h(1024) {}
  ~MoveAble() { delete i; }
  MoveAble(MoveAble&& m) : i(m.i), h(std::move(m.h)) { m.i = nullptr; }

  MoveAble(const MoveAble& m) : h(m.h) {
    i = new int;
    *i = *m.i;
  }
  int* i;
  HugeMem h;
};

class UnMoveAble {
 public:
  UnMoveAble(const UnMoveAble&) {}
  UnMoveAble(UnMoveAble&&) = delete;  // 显示去掉了移动构造功能
  int a;
};

// 不正确的用法，m的声明周期内就将其成员指针赋空，导致访问成员变量段错误
// 正确使用右值引用，应该传递的是将亡值，而不是后面还会用到的值，要由程序员保证，所以move的使用还是要多注意
//  move是强制给左值转换为右值，其等效于static_cast<T&&>(lvalue)
void test_case1() {
  HugeMem m(10);
  HugeMem m1(m);
  cout << m.get_data(3) << endl;
  HugeMem m2(std::move(m));
  cout << m.get_data(3) << endl;
}

MoveAble gettmp() {
  MoveAble tmp = MoveAble();
  cout << hex << "huge mem from " << __func__ << " @" << tmp.h.c << endl;
  return tmp;  // 函数返回临时对象，属于右值
}

int main() {
  // test_case1();
  MoveAble a(gettmp());
  cout << hex << "huge mem from " << __func__ << " @" << a.h.c << endl;
  /*
  如果显式声明了任何构造函数，则不会自动生成默认构造函数。
  如果显式声明了虚拟析构函数，则不会自动生成默认析构函数。
  如果显式声明了移动构造函数或移动赋值运算符，则：
      不自动生成复制构造函数。
      不自动生成复制赋值运算符。
  如果显式声明了复制构造函数、复制赋值运算符、移动构造函数、移动赋值运算符或析构函数，则：
      不自动生成移动构造函数。
      不自动生成移动赋值运算符。
  */
  // MoveAble b(a);//所以此句会编译出错，需要显示是声明拷贝构造函数
  MoveAble b = a;
  MoveAble c(b);
  // 检查类型是否是可以移动的
  cout << "class MoveAble is moveable " << is_move_constructible<MoveAble>::value << endl;
  cout << "class UnMoveAble is moveable " << is_move_constructible<UnMoveAble>::value << endl;
  return 0;
}