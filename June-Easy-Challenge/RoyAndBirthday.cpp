/*
ID: ashish1610
PROG: Roy and Birthday
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD	1000000007
#define ll	long long int
ll num[1000005],den[1000005];
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
	for(int i=1 ;i<=1000000;++i) 
		num[i]=(i* num[i-1])%MOD;
	den[1000000]=inverse(num[1000000]);
	for (int i=1000000;i>0;--i)
		den[i-1]=(i* den[i])% MOD;
}
int main()
{
	pre_cal();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		int vov_cnt=0,con_cnt=0,ar[26];
		memset(ar,0,sizeof(ar));
		for(int i=0;i<str.length();++i)
		{
			if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
				vov_cnt++;
			else
				con_cnt++;
			ar[str[i]-'a']++;
		}
		if(vov_cnt>con_cnt+1)
			printf("-1\n");
		else
		{
			ll ans=1;
			ans=(ans*num[con_cnt])%MOD;
			ans=(ans*npr(con_cnt+1,vov_cnt))%MOD;
			for(int i=0;i<26;++i)
			{
				if(ar[i]>1)
				{
					ans=(ans*den[ar[i]])%MOD;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
