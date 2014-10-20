/*
ID: ashish1610
PROG: P1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll ar[1000001],ar1[1000001];
ll n,ans=0;
int i;
int main()
{
	scanf("%lld",&n);
	for(i=0;i<n;++i)
		scanf("%lld",&ar[i]);
	for(i=0;i<n;++i)
		scanf("%lld",&ar1[i]);
	sort(ar,ar+n);
	sort(ar1,ar1+n);
	for(i=0;i<n;++i)
		ans=ans+ar[i]*ar1[i];
	printf("%lld\n",ans);
	return 0;
}
