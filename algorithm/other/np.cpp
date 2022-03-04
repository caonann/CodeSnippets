/*************************************************************************
	> File Name: np.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月29日 星期三 16时30分34秒
 ************************************************************************/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void knapsack(int products_count, int capacity, vector<int>& weight_array, vector<int>& value_array, vector<vector<int>>& result)
{
	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = 1; j <= capacity; ++j)
		{
			if (weight_array[i] > j) // 当前背包的容量 j 放不下第 i 件商品时
			{
				result[i][j] = result[i - 1][j]; // 放弃第 i 件商品，拿第 i - 1 件商品
			}
			else
			{
				int value1 = result[i - 1][j - weight_array[i]] + value_array[i]; // 拿走第 i - 1件商品
				int value2 = result[i - 1][j]; // 不拿走第 i - 1 件商品
				if (value1 > value2)
				{
					result[i][j] = value1;
				}
				else
				{
					result[i][j] = value2;
				}
			}
		}
	}
}

int main()
{

	while (1)
	{
		int products_count, capacity;
		vector<int> weight_array(1, 0);
		vector<int> value_array(1, 0);
		cout << endl<< "-----------------------------" << endl;
		cout << "please input products count and knapsack's capacity: " << endl; // 输入商品数量和背包容量
		cin >> products_count >> capacity;
		cout << "please input weight array for " << products_count << " products" << endl;
		for (int i = 1; i <= products_count; ++i) // 循环输入每件商品的重量
		{
			int tmp;
			cin >> tmp;
			weight_array.push_back(tmp);
		}
		cout << "please input value array for " << products_count << " products" << endl;
		for (int i = 1; i <= products_count; ++i) // 循环输入每件商品的价格
		{
			int tmp;
			cin >> tmp;
			value_array.push_back(tmp);
		}
		vector<vector<int>> result(products_count + 1, vector<int>(capacity + 1, 0)); // 结果数组
		knapsack(products_count, capacity, weight_array, value_array, result); // 调用动态规划算法
		cout << "knapsack result is " << result[products_count][capacity] << endl;
	}

	return 0;

}
