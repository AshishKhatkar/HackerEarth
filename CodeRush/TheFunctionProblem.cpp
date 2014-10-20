/*
ID: ashish1610
PROG: The function problem
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll comp(ll n)
{
	ll res=1;
	ll b=2;
	while(n)
	{
		if(n%2)
			res=(res*b)%MOD;
		b=(b*b)%MOD;
		n/=2;
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",comp(n));
	}
	return 0;
}
