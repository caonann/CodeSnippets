/*************************************************************************
	> File Name: AEasyTask.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月16日 星期四 19时27分41秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define RIGHT_IDX  2*nRootID+2
#define LEFT_IDX   2*nRootID+1

// 调整函数
void adjust(int data[], int Length, int nRootID,bool isMax=true)
{
	for (int MAX = LEFT_IDX; MAX <= Length - 1; MAX = LEFT_IDX)
	{
		if (MAX == Length - 1)
		{
			if (isMax && data[MAX] > data[nRootID] || !isMax && data[MAX] < data[nRootID])
			{
				std::swap(data[MAX], data[nRootID]);
				return;
			}
		}
		else if (isMax && data[RIGHT_IDX] > data[LEFT_IDX] || !isMax && data[RIGHT_IDX] < data[LEFT_IDX])
		{
			MAX = RIGHT_IDX;
		}

		// 用最大节点和根节点比较
		if (isMax && data[MAX] > data[nRootID] || !isMax && data[MAX] < data[nRootID])
		{
			std::swap(data[MAX], data[nRootID ]);
			nRootID = MAX;
			continue;
		}

		return;
	}
}

int heapSortMax(int *A, int n)
{
	// write code here
	if (A == nullptr || n <= 0) return -1;
	// 构建初始堆
	for (int rootid = n / 2 - 1; rootid >= 0; rootid--) adjust(A , n, rootid);
	return A[0];
}

int heapSortMin(int *A, int n)
{
	// write code here
	if (A == nullptr || n <= 0) return -1;
	for (int rootid = n / 2 - 1; rootid >= 0; rootid--) adjust(A , n, rootid,false);
	return A[0];
}

int main()
{
	int nGroups, nCount;
	scanf("%d\n", &nGroups);
	for(int i=0;i<nGroups;i++)
	{
		scanf("%d\n", &nCount);
		std::vector<int> arr;
		for(int j=0;j<nCount;j++)
		{
			int tmp;
			scanf("%d", &tmp);
			arr.push_back(tmp);
		}
		while(1)
		{
			int max = heapSortMax(&arr[0],arr.size());
			int min = heapSortMin(&arr[1],arr.size()-1);
			//printf("max %d min %d \n",max,min);
			if(max == min) {
				printf("%d\n",max);
				break;
			}
			int diff = max - min;
			arr[0] = diff;
			arr[1] = diff;
		}
	}

    return 0;
}

