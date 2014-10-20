/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
bool prime[10000005];
void sieve()
{
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<=10000000;++i)
	{
		if(prime[i])
		{
			for(int j=2*i;j<=10000000;j+=i)
				prime[j]=false;
		}
	}
}
ll ar[12];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	assert(t>=1 && t<=10);
	sieve();
	while(t--)
	{
		int n;
		cin>>n;
		assert(n<=10 && n>=1);
		for(int i=0;i<n;++i)
		{
			cin>>ar[i];
			assert(ar[i]>=2 && ar[i]<=100000);
		}
		sort(ar,ar+n);
		for(int i=1;i<n;++i)
			assert(ar[i]>=ar[i-1]);
			
		ll ans=0;
		do
		{
			ll cur_sum=0;
			bool flag=true;
			for(int i=0;i<n;++i)
			{
				if(i==0)
					cur_sum=ar[i];
				else
					cur_sum=ar[i]+ar[i-1];
				if(!prime[cur_sum])
				{
					flag=false;
					break;
				}
			}
			if(flag)
				ans++;
		}while(next_permutation(ar,ar+n));
		cout<<ans<<endl;
	}
	return 0;
}
