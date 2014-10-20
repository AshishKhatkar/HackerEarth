/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int ar[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>ar[i];
	int maxx=ar[n-1];
	int ans=0;
	for(int i=n-2;i>=0;--i)
	{
		if(ar[i]<maxx)
			ans+=(maxx-ar[i]);
		else
			maxx=ar[i];
	}
	cout<<ans<<endl;
	return 0;
}
