/*
ID: ashish1610
PROG: Subset And
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,z;
		scanf("%d %d",&z,&n);
		int temp,ans=z;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&temp);
			ans=ans&temp;
		}
		if(ans==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
