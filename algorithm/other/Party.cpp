#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        long long k;
        scanf("%d %lld",&n,&k);
        vector<int> an;

        bool isTrue=false;
        an.push_back(-1);
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            an.push_back(a);
        }
        
        int index=1;
        int x=1;
        int wx=an[index];
        int tmp_k=0;
        std::map<int,int> tmpmap;
        for(auto &v:an){
            tmpmap[v]=0;
        }
        bool isBigN=false;
        while (true){
            while (1){
                if(index > n){
                    index=index-n;
                    isBigN=true;
                }else{
                    if(isBigN){
                        tmpmap[an[index]]++;
                    }
                    
                    break;
                }
            }
            
            if(wx == an[index]){
                tmp_k++;
            }else{
                wx=an[index];
                tmp_k=1;
            }
            //cout<<"tmpk "<<tmp_k<<endl;
            if(tmp_k>=k){
                printf("%d %d\n",x,an[index]);
                isTrue=true;
                break;
            }
            
            bool t=false;
            for(auto&v:tmpmap){
                //cout<<"test "<<v.first<<" "<<v.second<<endl;
                if(v.second <= 1 && v.first != -1 ){
                    t=true;
                }
            }

            if(!t){
                break;
            }
            index++;
            x++;
        }
        if(!isTrue){
            printf("INF\n");
        }
    }
    return 0;
}