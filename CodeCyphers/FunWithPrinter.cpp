/*
ID: ashish1610
PROG: Fun with printer
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,k,d;
		scanf("%lld %lld %lld",&n,&k,&d);
		ll sum=0,tmp;
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&tmp);
			sum+=tmp;
		}
		if(k-sum>=d)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
