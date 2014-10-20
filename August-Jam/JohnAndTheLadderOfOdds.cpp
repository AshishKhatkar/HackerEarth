/*
ID: ashish1610
PROG: John and ladder odds
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000009
ll ar[2][2]={{1,1},{1,0}},tmp[2][2]={{1,1},{1,0}};
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
void cal(ll b[2][2])
{
	ll x=(ar[0][0]*b[0][0]+ar[0][1]*b[1][0])%MOD;
	ll y=(ar[0][0]*b[0][1]+ar[0][1]*b[1][1])%MOD;
	ll z=(ar[1][0]*b[0][0]+ar[1][1]*b[1][0])%MOD;
	ll w=(ar[1][0]*b[0][1]+ar[1][1]*b[1][1])%MOD;
	ar[0][0]=x;
	ar[0][1]=y;
	ar[1][0]=z;
	ar[1][1]=w;
}
void solve(ll n)
{
	if(n<2)
		return;
	solve(n>>1);
	cal(ar);
	if(n&1)
		cal(tmp);
}
int main()
{
	ll t;
	inp(t);
	while(t--)
	{
		ar[0][0]=1,ar[0][1]=1,ar[1][0]=1,ar[1][1]=0;
		ll n;
		inp(n);
		solve(n-1);
		ll ans=ar[0][0];
		ar[0][0]=1,ar[0][1]=1,ar[1][0]=1,ar[1][1]=0;
		solve(n);
		ans=(ans*ar[0][0])%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
