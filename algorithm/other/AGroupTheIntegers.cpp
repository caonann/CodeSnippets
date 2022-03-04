/*************************************************************************
	> File Name: AGroupTheIntegers.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月22日 星期三 19时15分56秒
 ************************************************************************/

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int heshu[100000000];
int get_prime_number(unsigned int n)
{
	vector<unsigned int>prime_list;
	vector<bool> check;
	check.resize(n);
	unsigned int pos=0;
	for(unsigned int i=2;i<n;++i)
	{
		if(!check[i])
		{
			++pos;
			prime_list.push_back(i);
		}
		for(unsigned int j=0;j<pos && i*prime_list[j] <n;j++)
		{
			check[i*prime_list[j]]=true;
			if(i%prime_list[j] == 0)
			{
				break;
			}
		}
		heshu[i]=i-pos;
	}
	prime_list.push_back(1);

	return pos+1;
}

void get_heshu(int n){
	int sum=0;
	heshu[0]=1;
	heshu[1]=1;
	for(int i=2;i<=n;i++){
		if(i%2 == 0){
			sum++;
			heshu[i]=sum;
		}
	}
}

int getGroupNum(int n)
{
	return n-get_prime_number(n);
}
int main()
{
	get_heshu(10000000);
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		int ret = heshu[n-1];
		printf("%d\n",ret);
	}
    return 0;
}

