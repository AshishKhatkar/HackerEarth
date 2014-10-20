/*
ID: ashish1610
PROG: Powers of 2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll mp[1000005];
void pre_compute()
{
	for(int i=1;i<=1000000;++i)
		mp[i]=1;
	mp[1]=0;
	for(int i=2;i<=1000000;++i)
	{
		for(int j=i+i;j<=1000000;j+=i)
			mp[j]++;
	}
	for(int i=2;i<=1000000;++i)
		mp[i]+=mp[i-1];
}
int main()
{
	pre_compute();
	int t;
	ll n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",mp[n]);
	}
	return 0;
}
