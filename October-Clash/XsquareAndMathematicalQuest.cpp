/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
map<ll,ll>fact;
map<ll,ll>::iterator it;
bool marked[100005];
void factorize(ll n)
{
	ll res=0;
	for(int i=2;i<=(ll)sqrt(n);++i)
	{
		res=0;
		while(n%i==0)
		{
			res++;
			n/=i;
		}
		fact[i]+=res;
	}
	if(n>=2)
		fact[n]++;
}
int main()
{
	int n;
	scanf("%d",&n);
	ll ar[n],ans=1;
	for(int i=0;i<n;++i)
		scanf("%lld",&ar[i]);
	for(int i=0;i<n;++i)
		factorize(ar[i]);
	for(it=fact.begin();it!=fact.end();++it)
	{
		if(it->first%4==3)
		{
			if((it->second)&1)
			{
				ans=0;
				break;
			}
		}
		else if((it->first)%4==1)
			ans=(ans*(1+(it->second)))%MOD;
	}
	ans=(4*ans)%MOD;
	printf("%lld\n",ans);
	return 0;
}
