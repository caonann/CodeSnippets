#include <iostream>
#include <initializer_list>
#include <vector>
#include <map>
using namespace std;

class Mydata{
public:
    //重载操作符
    Mydata& operator [](initializer_list<int> l){
        cout<<"operator []"<<endl;
        for(auto it=l.begin();it!=l.end();++it){

        }
        return *this;
    }
    Mydata& operator=(int v){
        cout<<"operator ="<<endl;
        return *this;
    }
private:

};
int main(){
    int a[]={1,2,3};
    int a1[]{1,2,3};
    vector<int> a2{1,2,3};
    map<int,int> a3{{1,1},{2,2}};
    
    Mydata data;
    data[{1,2,3}]=1;
    return 0;
}