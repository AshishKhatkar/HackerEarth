/*
ID: ashish1610
PROG: Even and odd
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
		int r,c;
		scanf("%d %d",&r,&c);
		ll even=0,odd=0;
		ll temp=r/2;
		if(r%2)
			temp++;
		odd=temp*temp;
		temp=r/2;
		even=temp*(temp+1);
		temp=c;
		if(temp>r)
			printf("%lld %lld\n",even,odd);
		else
		{
			if((temp+1)%2)
			{
				temp=r-c;
				ll temp1=temp/2;
				if(temp%2)
					temp1++;
				odd=odd-(temp1*temp1);
				temp1=temp/2;
				even=even-(temp1*(temp1+1));
			}
			else
			{
				temp=r-c;
				ll temp1=temp/2;
				if(temp%2)
					temp1++;
				even=even-(temp1*temp1);
				temp1=temp/2;
				odd=odd-(temp1*(temp1+1));
			}
			printf("%lld %lld\n",even,odd);
		}
	}
	return 0;
}
