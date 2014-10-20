/*
ID: ashish1610
PROG:ART
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD 1000000007
/*	fast input	*/
inline void inp(ll &n) 
{
    	n=0;
	register ll ch=getchar_unlocked();
	ll sign=1;
    	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			sign=-1; 
		ch=getchar_unlocked();
	}
    	while(ch>='0'&&ch<='9')
            n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    	n=n*sign;
}
ll num[100001],den[100001];
ll mypow(ll base,ll po)
{
	if(po == 0 )
		return 1;
	if(po&1)
		return (base*(mypow(base,po-1))%MOD)%MOD;
	ll root = mypow(base,po>>1);
	return (root*root)%MOD;
}
ll ncr(ll n, ll r)
{
	if(r>n || r<0)
		return 0;
	return (((num[n]*den[r])%MOD)*den[n-r])%MOD;
}
ll inverse (ll x) 
{
	return mypow(x, MOD-2);;
}
void pre_cal() 
{
	num[0]=1;
	for(int i=1 ;i<=100000;++i) 
		num[i]=(i* num[i-1])%MOD;
	den[100000]=inverse(num[100000]);
	for (int i=100000;i>0;--i)
		den[i-1]=(i* den[i])% MOD;
}
int main()
{
	pre_cal();
	ll t;
	inp(t);
	while(t--)
	{
		ll n,k;
		inp(n);
		inp(k);
		ll ans = 0;
		ll ar[n];
		for (int i = 0; i<n;i++)
			inp(ar[i]);
		sort(ar,ar+n);
		for(int i=n-k;i>=0;i--)
			ans = (ans+(ar[i]*ncr(n-i-1,k-1))% MOD)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
