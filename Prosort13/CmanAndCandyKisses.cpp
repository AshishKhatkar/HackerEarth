/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/*Power by exponentiation*/
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
ll ar[1000005];
ll num[1000005];
ll den[1000005];
void pre_compute()
{
	num[0]=1;
	for(int i=1;i<=1000000;++i)
		num[i]=(i*num[i-1])%MOD;
	den[1000000]=pow_mod(num[1000000],MOD-2)%MOD;
	for(int i=1000000;i>0;--i)
		den[i-1]=(i*den[i])%MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	pre_compute();
	while(t--)
	{
		ll n,r;
		cin>>n>>r;
		ll sum=0;
		for(int i=0;i<n;++i)
		{
			cin>>ar[i];
			sum+=ar[i];
		}
		ll ans=(num[n+r-sum-1]*den[n-1])%MOD;
		ans=(ans*den[r-sum])%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
