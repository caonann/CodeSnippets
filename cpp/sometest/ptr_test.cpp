#include <iostream>

struct S1 {
  int16_t a, b;
};

struct S2 {
  int32_t a;
};

void demo() {
  S2 s2;
  S1 *p = reinterpret_cast<S1 *>(&s2);
  p->a = 2;
  p->b = 1;

  std::cout << s2.a;  // 猜猜这里会输出多少？
}

int main() {
  demo();
  return 0;
}
