/*
ID: ashish1610
PROG: Crazy Kangaroo
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
		ll a,b,m;
		scanf("%lld %lld %lld",&a,&b,&m);
		ll x,y;
		if(a%m==0)
			x=a;
		else
			x=a+m-(a%m);
		if(b%m==0)
			y=b;
		else
			y=b-(b%m);
		ll ans=(y-x)/m+1;
		printf("%lld\n",ans);
	}
	return 0;
}
