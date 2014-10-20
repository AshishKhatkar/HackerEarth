/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		long long int sum=0;
		for(int i=0;i<str.length();++i)
		{
			if(str[i]=='_')
				continue;
			sum=sum+(str[i]-'0');			
		}
		int ans=sum%9;
		if(ans)
			cout<<9-ans<<endl;
		else
			cout<<"0 or 9\n";
	}
	return 0;
}
