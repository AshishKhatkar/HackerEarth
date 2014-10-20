/*
ID: ashish1610
PROG: Vaisnhnav and Plywood
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
		ll n,k;
		scanf("%lld %lld",&n,&k);
		ll ans;
		if(n==1)
		{
			if(k==0)
				ans=0;
			else
				ans=8*k;
		}
		else if(n==5)
		{
			if(k==0)
				ans=4;
			else
				ans=8*k+4;
		}
		else
		{
			ans=4*k;
			if(k&1)
				ans=ans+5-n;
			else
				ans=ans+n-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
