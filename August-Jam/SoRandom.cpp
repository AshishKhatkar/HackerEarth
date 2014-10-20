/*
ID: ashish1610
PROG: So random
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double prob;
		int tm;
		scanf("%lf %d",&prob,&tm);
		double ans=pow((1-prob),((tm*1.0)/1440));
		printf("%0.4lf\n",(1-ans));
	}
}
