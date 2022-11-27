#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
class A {
 public:
  void show() {
    for (int i = 0; i < 10; i++) {
      cout << "show " << i << endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
  int a_ = 1;
};

std::vector<std::shared_ptr<A>> vas;

void func_ptr() {
  auto ptr = std::make_shared<A>();
  cout << "use count" << ptr.use_count() << endl;

  // vas.push_back(ptr);
  vas.emplace_back(ptr);
  auto t = std::thread([&ptr] {
    // ptr->show();
    printf("thread use count %ld\n", ptr.use_count());
  });
  t.join();

  cout << "use count" << ptr.use_count() << endl;
  cout << "use count vas" << vas[0].use_count() << endl;
}

int main() {
  func_ptr();
  cout << "main func usecout" << vas[0].use_count() << endl;
  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}