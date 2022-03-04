#include <iostream>
#include <stdio.h>
#include <vector>
#include <inttypes.h>
using namespace std;
int  main(){
    long long  T;
    scanf("%lld\n",&T);
    for( long long  i=0;i<T;i++){
        long long  n;
        scanf("%lld\n",&n);
        long long  count_zero=0;
        long long count=0;
        for( long long  i=0;i<n;i++)
        {
            long long  a;
            scanf("%lld",&a);
            if (a==0){
                count_zero++;
            }else if(a<0){
                count++;
            }
        }
        long long zhengshu=n-count-count_zero;
        
        long long diff= abs(zhengshu-count);
        if (diff == 1){
            printf("Yes\n");   
        }
        else if (diff-1 <=count_zero){
            printf("Yes\n");   
        }
        else{
            printf("No\n");   
        }
    
    }
    return 0;
}