/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD	1000000007
#define ll	long long int
ll num[2000005],den[1000005];
ll mypow(ll base,ll po)
{
	if(po == 0 )
		return 1;
	if(po&1)
		return (base*(mypow(base,po-1))%MOD)%MOD;
	ll root = mypow(base,po>>1);
	return (root*root)%MOD;
}
ll npr(ll n, ll r)
{
	return (num[n]*den[n-r])%MOD;
}
ll inverse (ll x) 
{
	return mypow(x, MOD-2);;
}
void pre_cal() 
{
	num[0]=1;
	for(int i=1 ;i<=2000004;++i) 
		num[i]=(i* num[i-1])%MOD;
	den[1000001]=inverse(num[1000001]);
	for (int i=1000001;i>0;--i)
		den[i-1]=(i* den[i])% MOD;
}
int main()
{
	pre_cal();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans=(num[2*n]*den[n+1])%MOD;
		ans=(ans*den[n])%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
