/*
 *功能：传入一个网口名，获取相应的IP地址
 * */

#include <arpa/inet.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

char *interface2ip(char *infName) {
  struct ifaddrs *ifAddrStruct;
  void *tmpAddrPtr = NULL;
  char ip[16];
  memset(ip, 0, sizeof(ip));
  static char infIP[16];
  getifaddrs(&ifAddrStruct);
  while (ifAddrStruct != NULL) {
    if (ifAddrStruct->ifa_addr->sa_family == AF_INET &&
        0 == strcmp(ifAddrStruct->ifa_name, infName)) {
      tmpAddrPtr = &((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
      inet_ntop(AF_INET, tmpAddrPtr, ip, INET_ADDRSTRLEN);
      // printf("eth0 ip :%s\n",ip);
      strcpy(infIP, ip);
      // printf("infIP is :%s\n",infIP);
    }
    ifAddrStruct = ifAddrStruct->ifa_next;
  }
  // free ifaddrs
  freeifaddrs(ifAddrStruct);
  // return 0;
  return infIP;
}

int main() {
  char infName[] = "eth1";
  printf("the result is : %s\n", interface2ip(infName));

  return 0;
}