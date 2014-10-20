/*
ID: ashish1610
PROG: Love with primes
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
bool prime[1000005]={false};
ll ans[1000005]={0};
bool check(int i)
{
	while(i)
	{
		if(i%10==7)
			return true;
		i/=10;
	}
	return false;
}
void sieve()
{
	for(ll i=2;i*i<1000005;++i)
		if(!prime[i])
			for(ll j=i*i;j<1000005;j+=i)
				prime[j] = 1;
	ll cnt=0;
	ans[1]=0;
	ans[0]=0;
	for(int i=2;i<1000005;++i)
	{
		if(!prime[i] && check(i))
			cnt++;
		ans[i]=cnt;
	}
}
int main()
{
	sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld %lld",&n,&m);
		if(ans[m]-ans[n-1]==0)
			printf("-1\n");
		else
			printf("%d\n",ans[m]-ans[n-1]);
	}
	return 0;
}
