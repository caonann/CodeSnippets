#include <assert.h>
#include <stdio.h>

#include <iostream>

using namespace std;

// 注释 //,/**/
// 控制流
// 基本内置变量类型

class A {
  int a;
  virtual int getSomeNumber() { return 3; };
};

class B : public A {
  virtual int getSomeNumber() override { return 0; }
  int b;
  // int c;
};

int main() {
  /*
  在16位机中，int跟short int一样2字节，long 4字节；
  在32位机中，int 跟long int一样4字节，需要64位int就用long long int，即int64;
  在64位机中，int还是4字节，long int 8字节。
  */
  printf("size of bool:%d,char:%d ,int:%d, short:%d,float:%d, double:%d,long:%d,long long:%d,long double:%d\n",
         sizeof(bool), sizeof(char), sizeof(int), sizeof(short), sizeof(float), sizeof(double), sizeof(long),
         sizeof(long long), sizeof(long double));

  // 字面常量
  1L;
  012;
  0xC1;

  printf("size of class A %d\n", sizeof(A));
  printf("size of class B %d\n", sizeof(B));
  int *p = nullptr;
  printf("size of pointer is %d\n", sizeof(p));

  int mod = 0 % 2;
  cout << "mod is " << mod << endl;
  return 0;
}