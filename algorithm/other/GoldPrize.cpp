#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

#define right_idx  2*nRootID+2
#define left_idx   2*nRootID+1

class HeapSort
{
public:
    int *heapSort(int *A, int n)
    {
        // write code here
        if (A == nullptr || n <= 0)
        {
            return A;
        }

        // 构建初始堆
        for (int rootid = n / 2 - 1; rootid >= 0; rootid--)
        {
            adjust(A , n, rootid);
        }

        // 交换最后一个节点和根节点的值
        for (int length = n - 1; length > 0; length--)
        {
            // 调整
            std::swap(A[length], A[0]);
            adjust(A , length, 0);
        }

        return A;
    }

    // 调整函数
    void adjust(int data[], int Length, int nRootID)
    {
        for (int MAX = left_idx; MAX <= Length - 1; MAX = left_idx)
        {
            if (MAX == Length - 1)
            {
                if (data[MAX] < data[nRootID])
                {
                    std::swap(data[MAX], data[nRootID]);
                    return;
                }
            }
            else if (data[right_idx] < data[left_idx])
            {
                MAX = right_idx;
            }

            // 用最大节点和根节点比较
            if (data[MAX] < data[nRootID])
            {
                std::swap(data[MAX], data[nRootID ]);
                nRootID = MAX;
                continue;
            }

            return;
        }
    }
};

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,k;
        scanf("%d %d",&n,&k);
        std::vector<int> an;
        for(int i=0;i<n;i++){
            int ai;
            scanf("%d",&ai);
            an.push_back(ai);
        }
        
        int bimax=0;
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            if (i==0){
                bimax= tmp;
            }
        }

        an[0]+=bimax;
        int tmax=an[0];
        HeapSort h;
        
        h.heapSort(static_cast<int *>(&an[0]), static_cast<int>(an.size()));

        std::map<int,int> tmpmap;
        int desc=0;
        for(const auto&v:an){
            if(tmpmap.find(v) !=tmpmap.end()){
                desc++;
            }else{
                tmpmap[v]=++desc;
            }
        }
        /*
        for(auto &v:tmpmap){
            cout<<v.first<<" "<<v.second<<endl;
        }
        */
        if(tmpmap[tmax] <= k){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}