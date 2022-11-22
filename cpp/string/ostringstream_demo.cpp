#include <iostream>
#include <memory>
#include <sstream>
std::ostringstream stream_url;
class A {
 public:
  A(const std::string& a) { bb_ = a; }
  void show() { std::cout << bb_ << std::endl; }

 private:
  std::string bb_;
};
int main() {
  stream_url << "aaa" << 123 << "###";
  std::cout << stream_url.str();

  auto a = std::make_shared<A>(stream_url.str());
  a->show();
  return 0;
}