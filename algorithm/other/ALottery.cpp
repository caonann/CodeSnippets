/*************************************************************************
	> File Name: ALottery.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年06月03日 星期三 20时02分43秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long long do_calc(std::vector< std::vector<unsigned int> >& array,int x,int y){
	int size = array[0].size();
	vector<long long> sum_row;
	vector<long long> sum_col;
	sum_row.resize(size);
	sum_col.resize(size);

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			sum_row[i]+=array[i][j];
			sum_col[j]+=array[j][i];
		}
	}

	unsigned int min = 1000000000;
	int pos_duijiao_min_x=-1;
	int pos_duijiao_min_y=-1;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i == j){
				if(array[i][j] < min){
					min = array[i][j];
					pos_duijiao_min_x = i;
					pos_duijiao_min_y = j;
				}
			}
		}
	}

	for(int i=size-1;i>=0;i--){
		for(int j=0;j<size;j++){
			if(i == j){
				if(array[i][j] < min){
					min = array[i][j];
					pos_duijiao_min_x = i;
					pos_duijiao_min_y = j;
				}
			}
		}
	}


	if(size%2 ==0){

	}else{

	}
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		long long max=0;
		int pos_x_max=-1;
		int pos_y_max=-1;
		std::vector<std::vector<unsigned int> > array_;
		array_.resize(n);
		for (int j=0;j<n;j++){
			long long sum_line=0;
			array_[j].resize(n);
			for(int k=0;k<n;k++){
				unsigned int val;
				scanf("%u",&val);
				array_[j][k]=val;
				if(j == k) continue;
				if(val > max){
					pos_x_max=j;
					pos_y_max=k;
				}
			}
		}
		long long ret = do_calc(array_,pos_x_max,pos_y_max);
		printf("%lld\n",ret);
	}
    return 0;
}

