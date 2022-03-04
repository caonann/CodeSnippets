#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
using namespace std;
/*
写一个函数将 IPv4 地址字符串（仅包含数字、点、空格）转化成 32 位整数。
另外，数字和点之间的空格是合法的，其他情况均为非法地址，要求输出合法地址的 32 位整型结果
*/

int main()
{
  //将整数IP转换为字符串表示的IP
  int dwAddr = inet_addr("192.168.0.1");
  cout << "NO1 :IP的整数形式 " << dwAddr <<endl;
 
  //将字符串形式的IP转换为整数形式表示，方法一
  struct in_addr inAddr;
  inAddr.s_addr = dwAddr;
  cout << "NO2: IP的字符串形式 " <<  inet_ntoa(inAddr) << endl;
 
  //将字符串形式的IP转换为整数形式表示，方法二
  unsigned char *pch = (unsigned char*)&dwAddr;
  char szIPAddr[64] = {0};
  sprintf(szIPAddr, "%d.%d.%d.%d", *pch, *(pch+1), *(pch+2),*(pch+3));
  cout << "NO3: IP的字符串形式 " << szIPAddr << endl;
 
   return 1;
}