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
		string str;
		cin>>str;
		for(int i=0;i<26;++i)
			ar[i].clear();
		ll len=str.length();
		for(int i=0;i<len;++i)
			ar[str[i]-'a'].push_back(i);
		ll ans=0;
		for(int i=0;i<26;++i)
			for(int j=1;j<ar[i].size();++j)
				ans=(ans+pow_mod(2,ar[i][j]-ar[i][j-1]))%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
