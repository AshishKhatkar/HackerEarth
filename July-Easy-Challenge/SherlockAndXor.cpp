/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define mod	1000000007
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll tmp,even=0,odd=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&tmp);
			if(tmp&1)
				odd++;
			else
				even++;
		}
		ll ans=odd*even;
		cout<<ans<<endl;
	}
	return 0;
}
