/*
ID: ashish1610
PROG: Find the ring
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
		int k,n;
		scanf("%d %d",&k,&n);
		if(k==2 && n==0)
			printf("2\n");
		else if(k%2==0 && n%2==0)
			printf("0\n");
		else if(k%2==0)
			printf("1\n");
		else if(n%2==0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
