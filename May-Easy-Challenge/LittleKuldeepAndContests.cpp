/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
int main()
{
	int n;
	cin>>n;
	v.clear();
	while(n--)
	{
		int shr,smin,ehr,emin;
		char s1,s2,s3;
		cin>>shr>>s1>>smin>>s2>>ehr>>s3>>emin;
		int st=shr*60+smin;
		int en=ehr*60+emin;
		v.push_back(make_pair(st,en));
	}
	sort(v.begin(),v.end());
	bool flag=true;
	for(int i=1;i<v.size();++i)
	{
		if(v[i].first<v[i-1].second)
		{
			flag=false;
			break;
		}
	}
	if(flag)
		cout<<"Who needs a moderator?\n";
	else
		cout<<"Will need a moderator!\n";
	return 0;
}
