//
// Created by cn on 2019/4/25.
//

#include <assert.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <atomic>
#include <deque>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <thread>
#include <type_traits>
#include <vector>

using namespace std;

atomic_llong total{0};
long long total2{0};

void func_total(int) {
  for (int64_t i = 0; i < 100000000LL; i++) {
    total++;
    total2++;
    // usleep(1);
  }
}

void test_thread_demo1() {
  auto func = [](int) -> void {
    for (int64_t i = 0; i < 100000000LL; i++) {
      total++;
    }
  };

  std::thread t1(func_total, 0);
  std::thread t2(func_total, 0);
  t1.join();
  t2.join();
  cout << "total is " << total << endl;
  cout << "total2 is " << total2 << endl;
  // pthread_create();
}

int main() {
  cout << "trehad_demo" << endl;
  // todo:得到得结果不符合预期
  test_thread_demo1();

  return 0;
}