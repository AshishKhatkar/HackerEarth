/*
ID: ashish1610
PROG: Substring Count
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
/*	fast input	*/
inline void inp(int &n) 
{
    	n=0;
	register int ch=getchar_unlocked();
	int sign=1;
    	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			sign=-1; 
		ch=getchar_unlocked();
	}
    	while(ch>='0'&&ch<='9')
            n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    	n=n*sign;
}
int main()
{
	map<string, vector<int> >mp;
	vector<int>::iterator it1;
	map<string,vector<int> >::iterator it;
	int n,len,l,r,q,sz,i,j,k,ln,ans1,ans2;
	//scanf("%d",&n);
	inp(n);
	string str,tmp,to_check;
	for(i=0;i<n;++i)
	{
		cin>>str;
		len=str.length();
		for(j=0;j<len;++j)
		{
			tmp="";
			tmp.push_back(str[j]);
			for(k=j+1;k<len;++k)
			{
				mp[tmp].push_back(i+1);
				tmp.push_back(str[k]);
			}
			mp[tmp].push_back(i+1);
		}
	}
	for(it=mp.begin();it!= mp.end();++it)
	{
		it1=unique((it->second).begin(),(it->second).end());
		(it->second).resize(distance((it->second).begin(),it1));
	}
	//scanf("%d",&q);
	inp(q);
	while(q--)
	{
		inp(l);
		//scanf("%d %d",&l,&r);
		inp(r);
		cin>>to_check;
		ans1=upper_bound(mp[to_check].begin(),mp[to_check].end(),r)-mp[to_check].begin();
		ans2=lower_bound(mp[to_check].begin(),mp[to_check].end(),l)-mp[to_check].begin();
		printf("%d\n",ans1-ans2);
	}
	return 0;
}
