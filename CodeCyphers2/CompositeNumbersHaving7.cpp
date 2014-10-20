/*
ID: ashish1610
PROG: Vaishnav and Composites
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
bool prime[1000005]={true};
vector<ll> P;
int ans[1000005];
void sieve()
{
	for(ll i=2;i<=1000000;++i)
	{
		if(prime[i])
		{
			P.push_back(i);
			for(ll j=i*i;j<=1000000;j+=i)
				prime[j]=false;
		}
	}
}
bool contains(int n)
{
	while(n)
	{
		int rem=n%10;
		if(rem==7)
			return true;
		n/=10;
	}
	return false;
}
void pre_compute()
{
	ans[0]=0;
	ans[1]=0;
	for(int i=2;i<=1000000;++i)
	{
		if(!prime[i] && contains(i))
			ans[i]=ans[i-1]+1;
		else
			ans[i]=ans[i-1];
	}
}
int main()
{
	memset(prime,true,sizeof(prime));
	sieve();
	pre_compute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		if(ans[n]-ans[m-1] == 0)
			printf("-1\n");
		else
			printf("%d\n",(ans[n]-ans[m-1]));
	}
	return 0;
}
