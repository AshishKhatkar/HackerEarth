/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll ans[1000005];
void pre_compute()
{
	ans[0]=0;
	ans[1]=0;
	ans[2]=0;
	ans[3]=0;
	ans[4]=0;
	for(ll i=5;i<=1000000;++i)
	{
		ll tmp=i;
		ll cnt=0;
		ll pw=5;
		while(pw<=tmp)
		{
			cnt+=(tmp/pw);
			pw*=5;
		}
		ans[i]=cnt;
	}
	for(int i=1;i<=1000000;++i)
		ans[i]+=ans[i-1];
}
int main()
{
	pre_compute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%lld\n",ans[b]-ans[a-1]);
	}
	return 0;
}
