/*
ID: ashish1610
PROG: Four Squares
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll ans=0;
		for(ll i=1;i<=(ll)sqrt(n);++i)
		{
			if(n%i==0)
			{
				if(i%4!=0)
					ans+=i;
				if(i*i!=n)
				{
					if((n/i)%4!=0)
						ans+=(n/i);
				}
			}
		}
		ans*=8;
		printf("%lld\n",ans);
	}
	return 0;
}
