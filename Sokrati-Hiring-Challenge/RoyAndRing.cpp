/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD	1000000007
#define ll	long long int
ll a[2][2]={{1,1},{1,0}},b[2][2]={{1,1},{1,0}};
void mul(ll c[2][2])
{
	ll w=a[0][0]*c[0][0]+a[0][1]*c[1][0];
	ll x=a[0][0]*c[0][1]+a[0][1]*c[1][1];
	ll y=a[1][0]*c[0][0]+a[1][1]*c[1][0];
	ll z=a[1][0]*c[0][1]+a[1][1]*c[1][1];
	a[0][0]=w%MOD;
	a[0][1]=x%MOD;
	a[1][0]=y%MOD;
	a[1][1]=z%MOD;
}
void exp_pow(ll n)
{
	if(n==0 || n==1)
		return;
	exp_pow(n/2);
	mul(a);
	if(n%2)
		mul(b);
}
ll solve(ll n)
{
	a[0][0]=1;
	a[0][1]=1;
	a[1][0]=1;
	a[1][1]=0;
	if(n==0)
		return 0;
	exp_pow(n-1);
	return a[0][0];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll tmp=n/2;
		if(n%2)
			tmp++;
		ll ans=solve(tmp);
		ans=(ans*ans)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
