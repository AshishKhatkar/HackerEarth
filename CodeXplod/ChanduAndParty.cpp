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
ll solve (ll n, ll r) 
{
	vector<ll> p;
	for (ll i=2; i*i<=n; ++i)
		if (n % i == 0) 
		{
			p.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		p.push_back (n);
	ll sum = 0;
	for (ll msk=1; msk<(1<<p.size()); ++msk) 
	{
		ll mult = 1,
		bits = 0;
		for (ll i=0; i<(int)p.size(); ++i)
			if (msk & (1<<i)) 
			{
				++bits;
				mult *= p[i];
			}
		ll cur = r / mult;
		if (bits % 2 == 1)
			sum += cur;
		else
			sum -= cur;
	}
	return r - sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll r,n;
		cin>>r>>n;
		cout<<solve(n,r)<<endl;
	}
	return 0;
}
