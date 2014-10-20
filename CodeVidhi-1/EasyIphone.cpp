#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,mod=0;
	cin>>a>>b;
	long long int ans=a;
	while(true)
	{
		if(a<b)
			break;
		ans+=(a/b);
		mod=a%b;
		a/=b;
		a+=mod;
	}
	cout<<ans<<endl;
	return 0;
}
