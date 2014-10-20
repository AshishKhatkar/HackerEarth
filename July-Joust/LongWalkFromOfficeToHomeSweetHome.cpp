/*
ID: ashish1610
PROG: P2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll adj[55][55],adj1[55][55],n,u,v;
ll k;
ll ans=0;
void mul(int type)
{
	ll c[55][55];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			c[i][j]=0;
			for(int k=0;k<n;++k)
			{
				if(type==1)
					c[i][j]=(c[i][j]+adj[i][k]*adj[k][j])%MOD;
				else
					c[i][j]=(c[i][j]+adj[i][k]*adj1[k][j])%MOD;
			}
		}
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			adj[i][j]=c[i][j]%MOD;
}
void solve(ll n)
{
	if(n<2)
		return;
	solve(n>>1);
	mul(1);
	if(n&1)
		mul(2);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld %lld %lld %lld",&n,&k,&u,&v);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				scanf("%lld",&adj[i][j]);
				adj1[i][j]=adj[i][j];
			}
		solve(k);
		printf("%lld\n",adj[u][v]);
	}
	return 0;
}
