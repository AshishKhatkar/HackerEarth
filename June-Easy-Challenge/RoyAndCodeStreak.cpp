/*
ID: ashish1610
PROG: Roy and code streak
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool solved[1000005];
int main()
{
	int t,x,y,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(solved,false,sizeof(solved));
		scanf("%d",&n);
		int ans=0,tmp=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",&x,&y);
			if(y==1)
			{
				if(!solved[x])
				{
					solved[x]=true;
					tmp++;
				}
			}
			else
			{
				ans=max(ans,tmp);
				tmp=0;
			}
		}
		ans=max(ans,tmp);
		printf("%d\n",ans);
	}
	return 0;
}
