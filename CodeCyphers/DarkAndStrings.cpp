/*
ID: ashish1610
PROG: Dark And Strings
LANG: C++
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
		list<ll> q,q1;
		string str;
		cin>>str;
		int len=str.length();
		for(int i=0;i<len;++i)
		{
			if(str[i]>='0' && str[i]<='9')
				q.push_back(str[i]-'0');
			else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='%')
				q1.push_back(str[i]);
		}
		if(q.size()==0)
			printf("-1\n");
		else
		{
			while(!q1.empty() && q.size()>1)
			{
				char op=q1.front();
				q1.pop_front();
				if(op=='+')
				{
						ll tmp=q.front();
					q.pop_front();
					ll tmp1=q.front();
					q.pop_front();
					q.push_front(tmp+tmp1);
				}
				else if(op=='-')
				{
					ll tmp=q.front();
						q.pop_front();
					ll tmp1=q.front();
					q.pop_front();
					q.push_front(tmp-tmp1);
				}
				else if(op=='*')
				{
					ll tmp=q.front();
					q.pop_front();
					ll tmp1=q.front();
					q.pop_front();
						q.push_front(tmp*tmp1);
				}
				else if(op=='/')
				{
					ll tmp=q.front();
					q.pop_front();
					ll tmp1=q.front();
					q.pop_front();
					q.push_front(tmp/tmp1);
				}
				else if(op=='%')
				{
					ll tmp=q.front();
					q.pop_front();
					ll tmp1=q.front();
					q.pop_front();
					q.push_front(tmp%tmp1);
				}
			}
			printf("%lld\n",q.front());
		}
	}
	return 0;
}
