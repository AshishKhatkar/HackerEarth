/*
ID: ashish1610
PROG: Supertables
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,n;
		scanf("%lld %lld %lld",&a,&b,&n);
		ll tmp=(a*b)/gcd(a,b);
		ll low=1, high=1000000000000000000LL;
		while(low<=high)
		{
			ll mid=(low+high)/2;
			ll cnt=mid/a+mid/b-mid/tmp;
			if(cnt>=n)
				high=mid-1;
			else
				low=mid+1;
		}
		cout<<low<<endl;
	}
	return 0;
}
