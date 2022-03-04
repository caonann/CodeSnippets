/*************************************************************************
	> File Name: BEWasyNumberGame.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月16日 星期四 21时52分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long getMax(std::vector<int>& arr,int m)
{
	long long sum=0;
	std::sort(arr.begin(),arr.end(),std::less<int>());
	int maxrange = 2*m >arr.size()?arr.size()-1 : 2*m-1;
	for(int i=maxrange,j=0;m>0;i--,m--,j++) sum += arr[i] * arr[j];
	return sum;
}

int main()
{
	long long nGroups;
	scanf("%d\n",&nGroups);
	for(long long i=0;i<nGroups;i++)
	{
		long long m,n;
		scanf("%d %d\n",&m,&n);
		vector<int> arr;
		for(long long j=0;j<m;j++)
		{
			long long tmp;
			scanf("%d",&tmp);
			arr.push_back(tmp);
		}
		long long ret = getMax(arr,n);
		printf("%lld\n",ret);
	}
    return 0;
}

