/*************************************************************************
	> File Name: ipmode.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月29日 星期三 16时55分22秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	for(int x=10;x<255;x++){
		for(int y=10;y<202;y++){
			for(int z=10;z<130;z++){
				for(int m=0;m<68;m++){
					for(int k=0;k<30;k++){
						for(int r=0;r<23;r++){
							for(int b=0;b<10;b++){
								int cpunum = x+2*y+4*z+8*m+16*k+24*r+32*b;
								int ipnum=x+y+z+m+k+r+b;
								if(cpunum >=1800 && cpunum <=1924 && ipnum >=134 && ipnum <=144)
								{
									printf("%d %d %d %d %d %d %d\n",x,y,z,m,k,r,b);
								}
							}
						}
					}
				}
			}
		}
	}
    return 0;
}

