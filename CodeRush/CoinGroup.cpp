/*
ID: ashish1610
PROG: Coin Group
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
		for(int i=1;i<=(int)(sqrt(n));++i)
		{
			if(n%i==0)
			{
				if(i!=n/i)
					ans+=2;
				else
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
