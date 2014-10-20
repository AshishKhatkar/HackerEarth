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
#define MOD	1000000007
long long int mw[10001];
long long int powmod(long long int a, long long int b)
{
	long long int x=1,y=a; 
	while(b>0)
	{
		if(b%2)
		{
			x*=y;
			x%=MOD;
		}
		y*=y;
		y%=MOD; 
		b/=2;
	}
	return x;
}
void pre_compute()
{
	mw[1]=1;
	for(long long int i=2;i<=10000;++i)
	{
		for(long long int j=1;j<=(long long int)(sqrt(i));++j)
		{
			if(i%j==0)
			{
				mw[i]=(mw[i]+powmod(j,i))%MOD;
				if(j*j!=i)
					mw[i]=(mw[i]+powmod(i/j,i))%MOD;
			}
		}
		mw[i]=(mw[i]+mw[i-1])%MOD;
	}
}
int main()
{
	pre_compute();
	long long int t,a,b;
	inp(t);
	while(t--)
	{
		inp(a);
		inp(b);
		/*for(int i=1;i<=10;++i)
			cout<<mw[i]<<" ";
		*/
		long long int ans=(MOD+mw[b]-mw[a-1])%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
