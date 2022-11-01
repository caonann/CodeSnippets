#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void func_test1(const string& a, string& b) {
  string c = "213";
  b = c;
}

int readToFile(const string& file_name, std::string& content, ios_base::openmode mode) {
  ifstream ifs;
  ifs.open(file_name, mode);
  if (!ifs.is_open()) {
    printf("fail open %s\n", file_name);
    return -1;
  }
  stringstream s;
  s << ifs.rdbuf();
  content = s.str();
  return 0;
}

int main() {
  string k;
  func_test1("aaa", k);
  cout << k << endl;
  std::string pic_bin;
  readToFile("/data/workspace/aidhpaas/live_adaptor_cplus/live/aidh/test/ffmpeg-demo/logo.png",
             pic_bin, std::ifstream::binary);
  printf("pic len %d\n", pic_bin.length());
  size_t a = 1;
  auto aa = a - 4096;
  cout << aa << endl;
  return 0;
}
