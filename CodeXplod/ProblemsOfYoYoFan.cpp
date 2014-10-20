/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll pow_mod(ll a, ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
vector<ll>ar[26];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll cnt=0;
		for(int i=1;i<=(ll)sqrt(n);++i)
		{
			if(n%i==0)
			{
				if(n/i * n/i == n)
					cnt++;
				else
					cnt+=2;
			}
		}
		cnt+=(n%2);
		cout<<cnt<<endl;
	}
	return 0;
}
