/*
ID: ashish1610
PROG: Roy and Profile Picture
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,w,h,n;
	cin>>l>>n;
	for(int i=0;i<n;++i)
	{
		cin>>w>>h;
		if(w<l || h<l)
			printf("UPLOAD ANOTHER\n");
		else
		{
			if(w==h)
				printf("ACCEPTED\n");
			else
				printf("CROP IT\n");
		}
	}
	return 0;
}
