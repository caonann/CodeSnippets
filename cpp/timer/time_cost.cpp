#include <unistd.h>
#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;
/*
c++耗时统计累
*/
class TimeCount {
 public:
  TimeCount(const std::string method = "") {
    start_ = system_clock::now();
    method_ = method;
  }

  ~TimeCount() {
    if (show_) {
      SinceBegin();
    }
  }

  void SinceBegin() {
    show_ = false;
    auto cost = calc();
    printf("%s cost %lf ms\n", method_.c_str(), cost);
  }

 private:
  double calc() {
    auto end = system_clock::now();
    auto duration = duration_cast<milliseconds>(end - start_);
    auto cost = double(duration.count()) * milliseconds::period::num;
    return cost;
  }
  time_point<system_clock> start_;
  std::string method_;
  bool show_ = true;
};

void sample_demo() {
  auto start = system_clock::now();
  // do something...
  sleep(1);

  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  auto cost =
      double(duration.count()) * microseconds::period::num / microseconds::period::den;  //纳秒
  // milliseconds毫秒用这个
  cout << "花费了" << cost << "秒" << endl;
  printf("%lf s\n", cost);
  printf("%lf ns\n", double(duration.count()) * microseconds::period::num);
}

void test_cost() {
  {
    auto a = TimeCount("1");
    sleep(2);
  }

  {
    auto b = TimeCount("2");
    usleep(30200);
  }

  auto c = TimeCount("3");
  sleep(0.1);
  c.SinceBegin();
}
int main() {
  test_cost();
  return 0;
}