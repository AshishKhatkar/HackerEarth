/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[][9]={{1,-2,2,2,-1,2,2,-2,3},{1,2,2,2,1,2,2,2,3},{-1,2,2,-2,1,2,-2,2,3}};
int ans=0,n;
void solve(int ar[])
{
	int ar1[3];
	if(max(ar[0],max(ar[1],ar[2]))>n)
		return;
	int c=1;
	while(max(ar[0],max(ar[1],ar[2]))*c<=n)
	{
		c++;
		ans++;
	}
	for(int i=0;i<3;++i)
	{
		ar1[0] = dp[i][0] * ar[0] + dp[i][1] * ar[1] + dp[i][2] * ar[2];
		ar1[1] = dp[i][3] * ar[0] + dp[i][4] * ar[1] + dp[i][5] * ar[2];
        ar1[2] = dp[i][6] * ar[0] + dp[i][7] * ar[1] + dp[i][8] * ar[2];
        solve(ar1);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		int ar[3]={3,4,5};
		solve(ar);
		printf("%d\n",ans);
	}
	return 0;
}
