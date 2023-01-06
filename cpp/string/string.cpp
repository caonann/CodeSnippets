#include <cassert>
#include <iostream>
using namespace std;
int main() {
  string s;
  cout << s[1];
  string s1 = "rtmp://xxx/live/stream";
  assert(s1.substr(0, 4) == "rtmp");
  return 0;
}