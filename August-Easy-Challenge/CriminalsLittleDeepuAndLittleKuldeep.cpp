/*
ID: ashish1610
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll ar[n];
		map<ll,int> m;
		for(int i=0;i<n;++i)
		{
			cin>>ar[i];
			m[ar[i]]++;
		}
		int ans=0;
		map<ll,int>::iterator it;
		for(it=m.begin();it!=m.end();++it)
		{
			ans=max(ans,it->second);
		}
		cout<<ans<<endl;
	}
	return 0;
}
