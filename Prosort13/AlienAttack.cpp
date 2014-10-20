/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/*Power by exponentiation*/
ll pow_mod(ll a, ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
/*Matrix Exponentiation*/
typedef vector<vector<ll> > matrix;
const int K=2;
matrix mul(matrix A, matrix B)
{
	matrix C(K+1,vector<ll>(K+1));
	for(int i=1;i<=K;++i)
		for(int j=1;j<=K;++j)
			for(int k=1;k<=K;++k)
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
	return C;
}
matrix mat_pow(matrix A, int p)
{
	if(p==1)
		return A;
	if(p&1)
		return mul(A,mat_pow(A,p-1));
	matrix tmp=mat_pow(A,p/2);
	return mul(tmp, tmp);
}
ll solve(ll n, ll ar[2])
{
	matrix ans(K+1,vector<ll>(K+1));
	ans[1][1]=0, ans[1][2]=1;
	ans[2][1]=2, ans[2][2]=1;
	if(n==1)
		return ar[0];
	ans=mat_pow(ans,n-1);
	ll res=0;
	for(int i=1;i<=K;++i)
		res=(res+ans[1][i]*ar[i-1])%MOD;
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{ 
		ll n;
		cin>>n;
		ll ar[2]={2,7};
		if(n<=2)
			cout<<ar[n-1]<<endl;
		else
			cout<<solve(n,ar)<<endl;
	}
	return 0;
}
