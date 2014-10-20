/*
ID: ashish1610
PROG: CLimbing Downstairs
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int ans[6]={3,1,1,2,1,1};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%d\n",ans[n%6]);
	}
	return 0;
}
