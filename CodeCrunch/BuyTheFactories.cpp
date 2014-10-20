/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll n, ar[1000005];
ll kadane()
{
	ll max_ending_here=ar[0], max_so_far=ar[0];
	for(int i=1;i<n;++i)
	{
		max_ending_here=max(ar[i], max_ending_here+ar[i]);
		max_so_far=max(max_so_far, max_ending_here);
	}
	return max_so_far;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>ar[i];
		cout<<kadane()<<endl;
	}
	return 0;
}
