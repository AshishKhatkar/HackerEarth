/*
ID: ashish1610
PROG: Big Values
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
	ll n;
	scanf("%lld",&n);
	for(ll i=0;i<n;++i)
	{
		ll ans1=(i<<1)%n;
		ll ans2=((i<<1)+1)%n;
		printf("%lld %lld %lld\n",i,ans1,ans2);
	}
	return 0;
}
