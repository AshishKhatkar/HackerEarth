/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
	if(b<=a && a%b==0)
		return b;
	if(a<b)
		return gcd(b,a);
	else
		return gcd(b,a%b);
}
int main()
{
	int t;	
	cin>>t;
	while(t--)
	{
		long long int n,r,ans=0;
		cin>>n>>r;
		r--;
		for(long long int i=1;i*i<=r;++i)
		{
			if(r%i==0)
				ans++;
			long long int temp=r/i;
			if(i!=temp && r%temp==0)
				ans++;
		}
		ans=n-ans;
		cout<<ans/gcd(ans,n)<<"/"<<n/gcd(ans,n)<<endl;
	}
	return 0;
}
