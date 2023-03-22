#include <iostream>
#include <queue>
using namespace std;

int main() {
  std::queue<std::string> a;
  std::string buf;
  for (int i = 0; i < 1000 * 1000; i++) {
    buf += "a";
  }
  cout << "done..." << endl;
  for (;;) {
    a.emplace(buf);
    cout << "before size: " << a.size() << endl;
    if (a.size() > 300) {
      a.pop();
      cout << "size: " << a.size() << endl;
    }
  }
  return 0;
}