/*
ID: ashish1610
PROG: Alien Language
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
		string str,str1;
		cin>>str>>str1;
		int ar[26],ar1[26];
		memset(ar,0,sizeof(ar));
		memset(ar1,0,sizeof(ar1));
		int len1=str.length();
		int len2=str1.length();
		for(int i=0;i<len1;++i)
			ar[str[i]-'a']++;
		for(int i=0;i<len2;++i)
			ar1[str1[i]-'a']++;
		bool poss=false;
		for(int i=0;i<26;++i)
		{
			if(ar[i]>0 && ar1[i]>0)
			{
				poss=true;
				break;
			}
		}
		if(poss)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
