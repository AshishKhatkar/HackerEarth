/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll ar[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i)
			scanf("%lld",&ar[i]);
		ll ans=0;
		sort(ar,ar+n);
		reverse(ar,ar+n);
		for(int i=0;i<n && k!=0;++i)
		{
			ans+=ar[i];
			k--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
