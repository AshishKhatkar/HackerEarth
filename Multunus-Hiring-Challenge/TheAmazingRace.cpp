/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD 1000000007
ll ar[1000005],r[1000005],f[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		memset(r,0,sizeof(r));
		memset(f,0,sizeof(f));
		for(int i=0;i<n;++i)
			scanf("%lld",&ar[i]);
		stack<int>s;
		r[0]=0;
		s.push(1);
		for(int i=1;i<n;++i)
		{
			while(!s.empty() && (ar[i]>ar[s.top()-1]))
				s.pop();
			if(s.empty())
				r[i]=i-1;
			else
				r[i]=i-s.top();
			s.push(i+1);
		}
		while(!s.empty())
			s.pop();
		f[n-1]=0;
		s.push(n);
		for(int i=n-1;i>=0;--i)
		{
			while(!s.empty() && (ar[i]>ar[s.top()-1]))
				s.pop();
			if(s.empty())
				f[i]=n-i;
			else
				f[i]=s.top()-i;
			s.push(i+1);
		}
		ll ans=0,tmp,maxx=-1;
		for(ll i=0;i<n;++i)
		{
			tmp=f[i]+r[i];
			tmp=(tmp*(i+1))%MOD;
			if(tmp>maxx)
			{
				maxx=tmp;
				ans=i+1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
