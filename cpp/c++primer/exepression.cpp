#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;
int func1(){
    printf(__func__);
    return 1;
}

int func2(){
    printf(__func__);
    return 2;
}
int main(){
    int i=0;
    cout<<i<<" "<<i++<<endl;
    cout<<func1()*(func2())<<endl;
    cout<<21%-5<<endl;
    
    return 0;
}