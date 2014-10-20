/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define mod	1000000007
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int day, year;
		string month;
		cin>>day>>month>>year;
		if(day==1)
		{
			if(month=="May" || month=="July" || month=="October" || month=="December")
				day=30;
			else if(month=="March")
			{
				if(year%400==0)
					day=29;
				else if(year%4==0 && year%100!=0)
					day=29;
				else
					day=28;
			}
			else
				day=31;
			if(month=="January")
			{
				year--;
				month="December";
				day=31;
			}
			else if(month=="February")
				month="January";
			else if(month=="March")
				month="February";
			else if(month=="April")
				month="March";
			else if(month=="May")
				month="April";
			else if(month=="June")
				month="May";
			else if(month=="July")
				month="June";
			else if(month=="August")
				month="July";
			else if(month=="September")
				month="August";
			else if(month=="October")
				month="September";
			else if(month=="November")
				month="October";
			else
				month="November";
		}
		else
			day--;
		cout<<day<<" "<<month<<" "<<year<<endl;
	}
	return 0;
}
