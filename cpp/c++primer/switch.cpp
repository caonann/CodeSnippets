#include <stdio.h>
#include <iostream>
using namespace std;
/*
只有当所有case都不匹配时才会进入default语句
当找到一个匹配（无论是case还是default）后，会进入下面的case语句，直到找到break才会跳出switch。
*/
int main() {
  bool b = false;
  while (!b) {
    int Answer;
    cout << "How many cars do you have?";
    cin >> Answer;
    switch (Answer) {
      case 1:
      case 2:
      case 3:
      case 4:
        cout << "You need more cars. ";
        b = true;
        continue;
      case 5:
      case 6:
      case 7:
      case 8:
        cout << "Now you need a house. ";
        break;
      default:
        cout << "What are you? A peace-loving hippie freak? ";
    }
  }

  cout << "\nPress ENTER to continue... " << endl;
  getchar();
  return 0;
}