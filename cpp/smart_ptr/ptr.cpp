#include <iostream>
using namespace std;

// 这里要注意下，定义指针的时候一定要初始化，否则默认不像go那样会给默认值，这会导致一些西沟场景会出错
class A {
 public:
  A() = default;

 private:
  int a = 0;
};

int main() {
  A *a;  // 不同编译器的版本可能行为不通，所以初始化判空是个好习惯
  if (a) {
    cout << "a is not null!" << a << endl;
  }
  return 0;
}