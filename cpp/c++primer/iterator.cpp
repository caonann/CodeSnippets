/*
 @filename   iterator.cpp
 @author     caonan
 @date       2022-04-11 07:42:20
 @reference
 @brief
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  // 测试迭代器的自增
  vector<int> arr1{1, 2, 3, 4, 5, 6, 7};
  auto it = arr1.begin();
  int a = (*it)++;
  // int a = *it++; 这里加不加括号都一样，都是先解引用it，让后再让迭代器加一

  cout << "a is " << a << endl;
  int b = *it;
  cout << "b is " << b << endl;
  return 0;
}
