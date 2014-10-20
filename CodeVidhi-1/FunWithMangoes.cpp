/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,u;
		cin>>n>>u;
		long long int ar[n];
		memset(ar,0,sizeof(ar));
		vector<pair<pair<long long int,long long int>,long long int> > v;
		while(u--)
		{
			long long int a,b,c;
			cin>>a>>b>>c;
			v.push_back(make_pair(make_pair(a,b),c));
		}
		int q;
		cin>>q;
		while(q--)
		{
			long long int index;
			cin>>index;
			long long int ans=0;
			for(int i=0;i<v.size();++i)
			{
				if(index>=v[i].first.first && index<=v[i].first.second)
					ans+=v[i].second;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
