/*
ID: ashish1610
PROG: 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll pow_mod(ll a, ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll l,b,d;
		scanf("%lld %lld %lld",&l,&b,&d);
		ll ans=(((l/d)%MOD)*((b/d)%MOD))%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
