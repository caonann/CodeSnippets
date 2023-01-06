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
#include <mutex>
#include <queue>
#include <thread>
#include <type_traits>
#include <vector>
using namespace std;

std::mutex g_m;

queue<int> g_que;
void func_read() {
  for (;;) {
    if (!g_que.empty()) {
      std::scoped_lock _(g_m);
      // std::lock_guard<std::mutex> gard(g_m);
      auto data = g_que.front();
      // sleep(1);
      g_que.pop();
    }
  }
}

void func_write() {
  for (;;) {
    // std::lock_guard<std::mutex> gard(g_m); c++17后应该用scoped_lock
    std::scoped_lock _(g_m);
    g_que.emplace(1);
    // sleep(2);  //如果加了sleep，就很不容易出发core，否则不加锁的话，操作一个队列很容易出问题
  }
}

int main() {
  std::thread t1(func_read);
  std::thread t2(func_write);
  t1.join();
  t2.join();
  return 0;
}