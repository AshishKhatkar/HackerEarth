/*
ID: ashish1610	
PROG: Vaishnav and Factorials
LANG: C++
*/
#include<bits/stdc++.h> 
using namespace std;
int final_ans[255];
void pre_compute()
{
	final_ans[0]=0;
	for(int n=1;n<=250;++n)
	{
		int ans[600],temp=0,index=0,m=1,cnt=0;
		memset(ans,0,sizeof(ans));
		ans[0]=1;
		for(int i=1;i<=n;++i)
		{
			index=0;
			int x;
			while(index<m)
			{
				x=ans[index]*i+temp;
				ans[index]=x%10;
				temp=x/10;
				index++;
			}
			while(temp!=0)
			{
				ans[index]=temp%10;
				temp/=10;
				m++;
				index++;
			}
		}
		index--;
		for(int i=m;i>=0;--i)
		{
			if(i==m && ans[i]==0)
				continue;
			if(ans[i]==4 || ans[i]==7)
				cnt++;
		}
		final_ans[n]=cnt;
	}
}
int main()
{
	pre_compute();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",final_ans[n]);
	}
	return 0;
} 
