/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD	1000000007
#define ll 	long long int
ll ans[100005];
void pre_compute()
{
	ans[0]=1;
	ans[1]=1;
	ans[2]=2;
	for(int i=3;i<=100000;++i)
	{
		ans[i]=(ans[i-1]+ans[i-2]+ans[i-3])%MOD;
	}
}
int main()
{
	pre_compute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
}
