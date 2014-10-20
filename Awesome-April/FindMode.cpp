/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
/*	fast input	*/
inline void inp(long long int &n) 
{
    	n=0;
	register long long int ch=getchar_unlocked();
	long long int sign=1;
    	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			sign=-1; 
		ch=getchar_unlocked();
	}
    	while(ch>='0'&&ch<='9')
            n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    	n=n*sign;
}
long long int cnt[1000001];
int main()
{
	long long int n,temp,t;
	inp(t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		inp(n);
		long long int mx1=0;
		for(int i=0;i<n;++i)
		{
			inp(temp);
			cnt[temp]++;
			mx1=max(temp,mx1);
		}
		long long int mx=0;
		for(long long int i=1;i<=mx1;++i)
			mx=max(mx,cnt[i]);
		for(long long int i=mx1;i>=1;--i)
		{
			if(cnt[i]==mx)
				printf("%lld ",i);
		}
		printf("\n");
	}
	return 0;
}
