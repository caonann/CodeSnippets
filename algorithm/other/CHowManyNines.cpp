/*************************************************************************
	> File Name: CHowManyNines.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月17日 星期五 13时02分56秒
 ************************************************************************/

#include <iostream>
#include <assert.h>
#include <vector>
#include <random>
using namespace std;

bool judgeLeapYear(int year)
{
	if(year%400 == 0 || year%4==0 && year%100 != 0) return true;
	return false;
}

int getMonthDay(int year,int month)
{
	std::vector<int> months_day{31,28,31,30,31,30,31,31,30,31,30,31};
	if(judgeLeapYear(year)) months_day[1]=29;
	return months_day[month-1];
}

int getNineCountDigt(int n)
{
	int sum=0;
	do
	{
		int mod = n % 10;
		if(mod==9) sum ++;
		n/=10;
	}while(n!=0);
	return sum;
}

int getEageDayLCount(int d)
{
	int tmpday=0;
	if(d>=9) tmpday++;
	if(d>=19) tmpday++;
	if(d>=29) tmpday++;
	return tmpday;
}

int getEageDayRCount(int d)
{
	int tmpday=3;
	if(d>9) tmpday--;
	if(d>19) tmpday--;
	if(d>29) tmpday--;
	return tmpday;
}

int getNineCount(int y1,int m1,int d1,int y2,int m2,int d2)
{
	int diffYear = y2-y1;
	int sum = 0;
	if(diffYear)
	{
		int eageday = getEageDayRCount(d1);
		sum = (12-m1)*3+eageday;
		if(!judgeLeapYear(y1) && m1 <=2 ) sum--;
		if(m1 <9) sum+=30;
		if(m1 == 9) sum+=(getMonthDay(y1,m1)-d1+1);

		eageday = getEageDayLCount(d2);
		sum += (m2-1)*3+eageday;
		if(!judgeLeapYear(y2) && m2 >=2 ) sum--;
		if(m2 >9) sum+=30;
		if(m2 ==9) sum+=d2;

		sum+= (diffYear-1)*(12*3+30);
		int leapYearCount=0;
		for(int y=y1+1;y<y2;y++) if(!judgeLeapYear(y)) leapYearCount++;
		sum-=leapYearCount;

		int totalday = getMonthDay(y1,m1)-d1+1;
		for(int i=m1+1;i<=12;i++) totalday+=getMonthDay(y1,i);
		sum+=getNineCountDigt(y1)*totalday;

		totalday= d2;
		for(int i=m2-1;i>=1;i--) totalday+=getMonthDay(y2,i);
		sum+=getNineCountDigt(y2)*totalday;

		for(int y=y1+1;y<y2;y++) {
			totalday = judgeLeapYear(y) ?totalday= 366:totalday=365;
			sum+=getNineCountDigt(y)*totalday;
		}
	}
	else{
		int diffmonth=m2-m1;
		if(diffmonth)
		{
			int eageday = getEageDayRCount(d1);
			sum+=eageday;
			eageday = getEageDayLCount(d2);
			sum+=eageday;
			sum+=(diffmonth-1)*3;
			if(m1<9 && m2>9) sum+=30;
			if(m1 == 9) sum+=getMonthDay(y1,m1)-d1+1;
			if(m2 == 9) sum+=d2;
			if(!judgeLeapYear(y1) && m1<=2 && m2 >=2) sum--;
			int totalday = getMonthDay(y1,m1)-d1+1;
			for(int i=m1+1;i<m2;i++) totalday+=getMonthDay(y1,i);
			totalday+= d2;
			sum+=getNineCountDigt(y1)*totalday;
		}
		else{
			for(int i=d1;i<=d2;i++)
			{
				if(getNineCountDigt(i)) sum++;
				sum+=getNineCountDigt(y1);
				if(m1 == 9) sum++;
			}
			return sum;
		}
	}
	return sum;
}

int year_9_table[9999-2000]={0};
int getOneYearNineCount(int year)
{
	int sum = (12*3+30);
	if(!judgeLeapYear(year)) sum--;
	int totalday = judgeLeapYear(year) ?totalday= 366:totalday=365;
	sum+=getNineCountDigt(year)*totalday;
	return sum;
}

void init()
{
	int sum = 0;
	for(int i=2000;i<=9999;i++){
		sum += getOneYearNineCount(i);
		year_9_table[i-2000]=sum;
	}
}
int getNineCountFaster(int y1,int m1,int d1,int y2,int m2,int d2){
	int diffYear = y2-y1;
	int sum=0;
	if(!diffYear){
		int diffmonth=m2-m1;
		if(diffmonth)
		{
			int eageday = getEageDayRCount(d1);
			sum+=eageday;
			eageday = getEageDayLCount(d2);
			sum+=eageday;
			sum+=(diffmonth-1)*3;
			if(m1<9 && m2>9) sum+=30;
			if(m1 == 9) sum+=getMonthDay(y1,m1)-d1+1;
			if(m2 == 9) sum+=d2;
			if(!judgeLeapYear(y1) && m1<=2 && m2 >=2) sum--;
			int totalday = getMonthDay(y1,m1)-d1+1;
			for(int i=m1+1;i<m2;i++) totalday+=getMonthDay(y1,i);
			totalday+= d2;
			sum+=getNineCountDigt(y1)*totalday;
		}
		else{
			for(int i=d1;i<=d2;i++)
			{
				if(getNineCountDigt(i)) sum++;
				sum+=getNineCountDigt(y1);
				if(m1 == 9) sum++;
			}
			return sum;
		}
	}else{
		int eageday = getEageDayRCount(d1);
		sum = (12-m1)*3+eageday;
		if(!judgeLeapYear(y1) && m1 <=2 ) sum--;
		if(m1 <9) sum+=30;
		if(m1 == 9) sum+=(getMonthDay(y1,m1)-d1+1);

		eageday = getEageDayLCount(d2);
		sum += (m2-1)*3+eageday;
		if(!judgeLeapYear(y2) && m2 >=2 ) sum--;
		if(m2 >9) sum+=30;
		if(m2 ==9) sum+=d2;

		int totalday = getMonthDay(y1,m1)-d1+1;
		for(int i=m1+1;i<=12;i++) totalday+=getMonthDay(y1,i);
		sum+=getNineCountDigt(y1)*totalday;

		totalday= d2;
		for(int i=m2-1;i>=1;i--) totalday+=getMonthDay(y2,i);
		sum+=getNineCountDigt(y2)*totalday;
		if(diffYear>1) sum += (year_9_table[y2-2000-1] - year_9_table[y1-2000]);

	}
	return sum;
}

void test()
{
	assert(judgeLeapYear(2012));
	assert(judgeLeapYear(2020));
	//assert(judgeLeapYear(2100));
	assert(!judgeLeapYear(1993));
	cout<<"getNineCountDigt "<<getNineCountDigt(9399)<<endl;
	cout<<"getNineCountDigt "<<getNineCountDigt(2399)<<endl;
	cout<<"getNineCountDigt "<<getNineCountDigt(2389)<<endl;
	cout<<"getNineCountDigt "<<getNineCountDigt(2387)<<endl;
	cout<<getNineCount(2017 ,4 ,9, 2017 ,5 ,9)<<endl; //4
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,3 ,1)<<endl; //2
	cout<<getNineCount(2100 ,5 ,1 ,2100 ,6 ,1)<<endl; //3
	cout<<getNineCount(2100 ,5 ,1 ,2100 ,8 ,9)<<endl; //10
	cout<<getNineCount(2100 ,5 ,1 ,2100 ,8 ,19)<<endl; //11
	cout<<getNineCount(2100 ,5 ,1 ,2101 ,5 ,1)<<endl; //35

	cout<<getNineCount(2100 ,5 ,1 ,2102 ,5 ,1)<<endl; //70
	cout<<getNineCount(2100 ,5 ,1 ,2103 ,5 ,1)<<endl; //105

	cout<<getNineCount(9996 ,2 ,1 ,9996 ,3 ,1)<<endl; //93
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,2 ,9)<<endl; //1
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,2 ,8)<<endl; //0
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,2 ,28)<<endl; //2
	cout<<getNineCount(9999 ,1 ,1 ,9999 ,12 ,31)<<endl; //1495
	cout<<getNineCount(2000 ,1 ,1 ,9999 ,12 ,31)<<endl; //1763534
	cout<<getNineCount(2100 ,9 ,1 ,2100 ,9 ,28)<<endl; //30
}

int getInt(int start,int end)
{
	std::random_device rd;
	std::default_random_engine e(rd());
	std::uniform_int_distribution<int> u(start, end);

    return u(e);
}

void test_faster(){
	for(int i=0;i<1000000;i++){
		int year1=getInt(2000,9999);
		int month1 = getInt(1,12);
		int day1 = getInt(1,getMonthDay(year1,month1));
		int year2=getInt(year1,9999);
		int month2 = getInt(1,12);
		int day2 = getInt(1,getMonthDay(year2,month2));
		printf("%d %d %d %d %d %d\n",year1,month1,day1,year2,month2,day2);
		int fasterret = getNineCountFaster(year1,month1,day1 , year2,month2 ,day2);
		int normalret = getNineCount(year1,month1,day1 , year2,month2 ,day2);
		assert(fasterret == normalret);
	}
	cout<<getNineCountFaster(2017 ,4 ,9, 2017 ,5 ,9)<<endl; //4
	cout<<getNineCountFaster(2100 ,2 ,1 ,2100 ,3 ,1)<<endl; //2
	cout<<getNineCountFaster(2100 ,5 ,1 ,2100 ,6 ,1)<<endl; //3
	cout<<getNineCountFaster(2100 ,5 ,1 ,2100 ,8 ,9)<<endl; //10
	cout<<getNineCountFaster(2100 ,5 ,1 ,2100 ,8 ,19)<<endl; //11
	cout<<getNineCountFaster(2100 ,5 ,1 ,2101 ,5 ,1)<<endl; //65

	cout<<getNineCountFaster(2100 ,5 ,1 ,2102 ,5 ,1)<<endl; //70
	cout<<getNineCountFaster(2100 ,5 ,1 ,2103 ,5 ,1)<<endl; //105

	cout<<getNineCountFaster(9996 ,2 ,1 ,9996 ,3 ,1)<<endl; //93
	cout<<getNineCountFaster(2100 ,2 ,1 ,2100 ,2 ,9)<<endl; //1
	cout<<getNineCountFaster(2100 ,2 ,1 ,2100 ,2 ,8)<<endl; //0
	cout<<getNineCountFaster(2100 ,2 ,1 ,2100 ,2 ,28)<<endl; //2
	cout<<getNineCountFaster(9999 ,1 ,1 ,9999 ,12 ,31)<<endl; //1495
	cout<<getNineCountFaster(2000 ,1 ,1 ,9999 ,12 ,31)<<endl; //1763534
	cout<<getNineCountFaster(2100 ,9 ,1 ,2100 ,9 ,28)<<endl; //30
}
int main()
{
	init();
	test_faster();
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		int y1,m1,d1,y2,m2,d2;
		scanf("%d %d %d %d %d %d",&y1,&m1,&d1,&y2,&m2,&d2);
		int ret = getNineCountFaster(y1,m1,d1,y2,m2,d2);
		printf("%d\n",ret);
	}
    return 0;
}

