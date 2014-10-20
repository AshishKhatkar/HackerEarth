/*
ID: ashish1610
PROG: Emma and Cipher
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
map<char,int> :: iterator it;
map<char,char> mapped;
map<char,char> :: iterator it1;
bool compare(pair<char,int> p1, pair<char,int> p2)
{
	if(p1.second!=p2.second)
		return p1.second>p2.second;
	else
		return p1.first>p2.first;
}
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		m.clear();
		string str;
		getline(cin,str);
		int len=str.length();
		for(int i=0;i<len;++i)
		{
			m[str[i]]++;
		}
		vector<pair<char,int> >v;
		for(it=m.begin();it!=m.end();++it)
			v.push_back(make_pair(it->first, it->second));
		sort(v.begin(),v.end(),compare);
		int sz=v.size();
		for(int i=0;i<=sz/2;++i)
		{
			mapped[v[i].first]=v[sz-1-i].first;
			mapped[v[sz-1-i].first]=v[i].first;
		}
		for(int i=0;i<len;++i)
			cout<<mapped[str[i]];
		cout<<endl;
	}
}
