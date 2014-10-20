/*
ID: ashish1610
PROG:LIP 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int main()
{
	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int ar[n][m],dp[n][m];
		for(int i=0;i<n;++i)
  			for(int j=0;j<m;++j)
          			cin>>ar[i][j];
		dp[n-1][m-1]= 1;
		for(int i=n-2;i>=0;--i)
		{
  			if(ar[i+1][m-1] > ar[i][m-1])
  				dp[i][m-1] = dp[i+1][m-1] +1;
  			else
        			dp[i][m-1] = 1;  
  		}    
      		for(int i=m-2;i>=0;--i)
  		{
  			if(ar[n-1][i+1] > ar[n-1][i])
				dp[n-1][i] = dp[n-1][i+1] +1;
  			else
        			dp[n-1][i] = 1;  
  		} 
  		for(int i=n-2;i>=0;--i)
  		{
  			for(int j=m-2; j>=0;--j)
  			{
  				if(ar[i][j]<ar[i+1][j] && ar[i][j]<ar[i][j+1] )
                       			dp[i][j] = 1 + max(dp[i+1][j], dp[i][j+1]);
				else if(ar[i][j]<ar[i+1][j])
					dp[i][j] = 1 + dp[i+1][j];
				else if(ar[i][j]<ar[i][j+1])
					dp[i][j] = 1 + dp[i][j+1];
   				else
					dp[i][j] = 1;
			}
		}
		cout<<dp[0][0]<<endl;
	}
	return 0;  
}
