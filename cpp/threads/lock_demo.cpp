#include <stdio.h>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex m_;
std::mutex b_;
void LockFunc3() {
  // 互斥锁同一个线程不可重入
  printf("LockFunc3 start!\n");
  std::scoped_lock a(m_);
  std::scoped_lock b(m_);
  std::scoped_lock c(m_);
  printf("LockFunc3 3!\n");
}
void LockFunc() {
  std::scoped_lock _(m_);
  std::scoped_lock b(b_);
  printf("lock func!\n");
}

void LockFunc2() {
  std::scoped_lock b(b_);
  std::scoped_lock _(m_);
  printf("lock func2!\n");
}

// 单线程测试，都没有问题
void SingaleThreadTest() {
  LockFunc();
  LockFunc2();
  LockFunc();
}

void TestFunc() {
  for (int i = 0; i < 1000; i++) {
    LockFunc();
  }
}

void TestFunc2() {
  for (int i = 0; i < 1000; i++) {
    LockFunc2();
  }
}
// 构造死锁场景
void MutiThreadTest() {
  std::thread t1(TestFunc);
  std::thread t2(TestFunc2);
  t1.join();
  t2.join();
  printf("done\n");
}

// 测试重入
void TestReEntry() {
  for (int i = 0; i < 100; i++) {
    LockFunc3();
  }
}
int main() {
  // MutiThreadTest();
  TestReEntry();
  return 0;
}