/*
ID: ashish1610
PROG: Roy and Cipher Disk
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ar[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		int tmp,cur_pos=0,cnt;
		for(int i=0;i<str.length();++i)
		{
			tmp=(str[i]-'a');
			if(tmp>=cur_pos)
			{
				if((ar[tmp]-ar[cur_pos])<=(ar[cur_pos]+26-ar[tmp]))
					printf("%d ",ar[tmp]-ar[cur_pos]);
				else
					printf("-%d ",ar[cur_pos]+26-ar[tmp]);
			}
			else
			{
				if((ar[cur_pos]-ar[tmp])<(ar[tmp]+26-ar[cur_pos]))
					printf("-%d ",ar[cur_pos]-ar[tmp]);
				else
					printf("%d ",ar[tmp]+26-ar[cur_pos]);
			}
			cur_pos=tmp;
		}
		printf("\n");
	}
	return 0;
}
