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
	ll ans=(n*(n-1))%MOD;
	ans=(ans*(n-2))%MOD;
	ans=(ans*(n-3))%MOD;
	ans=(ans*(n-4))%MOD;
	ans=(ans*(n-5))%MOD;
	ans=(ans*pow_mod(720,MOD-2))%MOD;
	printf("%lld\n",ans);
	return 0;
}
