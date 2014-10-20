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
ll ar[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		for(int i=0;i<n;++i)
			cin>>ar[i];
		ll cur_sum=ar[0],ind=0;
		bool flag=false;
		for(int i=1;i<=n;++i)
		{
			while(cur_sum>p && ind<i-1)
			{
				cur_sum=cur_sum-ar[ind];
				ind++;
			}
			if(cur_sum==p)
			{
				flag=true;
				break;
			}
			if(i<n)
				cur_sum+=ar[i];
		}
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
