#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>
using namespace std;


int main(){
    long long T;
    scanf("%lld\n",&T);
    
    for(long long i=0;i<T;i++){
        long long n;
        
        scanf("%lld\n",&n);
        if(n%2==1){
            for(int i=0;i<n;i++){
                long long tmp;
                scanf("%lld",&tmp);
            }
            printf("Yes\n");
        }
        else{
            std::vector<long long > oushu;
            std::vector<long long > jishu;
            for(int i=0;i<n;i++){
                long long tmp;
                scanf("%lld",&tmp);
                if(i%n==1){
                    jishu.push_back(tmp);
                }
                else{
                    oushu.push_back(tmp);
                }
               
            }

           std::sort(jishu.begin(),jishu.end());
            std::sort(oushu.begin(),oushu.end());
            bool t=false;
            for(int i=0;i<n/2;i++){
                if(oushu[i]>jishu[i]){
                    printf("No\n");
                    t=true;
                    break;
                }
            }
            if(!t){
                printf("Yes\n");
            }

        }
    }
    return 0;
}