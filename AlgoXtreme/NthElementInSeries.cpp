/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD	1000000007
#define REP(i,n) for (int i = 1; i <= n; i++)
typedef long long ll;
typedef vector<vector<ll> > matrix;
const int K = 5;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of sequence
ll solve(ll N, ll ar[5])
{

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1]=0, T[1][2]=1, T[1][3]=0, T[1][4]=0, T[1][5]=0;
	T[2][1]=0, T[2][2]=0, T[2][3]=1, T[2][4]=0, T[2][5]=0;
	T[3][1]=0, T[3][2]=0, T[3][3]=0, T[3][4]=1, T[3][5]=0;
	T[4][1]=0, T[4][2]=0, T[4][3]=0, T[4][4]=0, T[4][5]=1;
	T[5][1]=1, T[5][2]=2, T[5][3]=1, T[5][4]=1, T[5][5]=1;

    // raise T to the (N-1)th power
    if (N == 1)
        return ar[0];
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
    {
    	//cout<<T[1][i]<<" ";
        res = (res + T[1][i] * ar[i-1]) % MOD;
    }
  //  cout<<endl;
    return res;
}
/*
ll ar[5][5]={
	{0,1,0,0,0},
	{0,0,1,0,0},
	{0,0,0,1,0},
	{0,0,0,0,1},
	{1,2,1,1,1}};
ll tmp[5][5]={
	{0,1,0,0,0},
	{0,0,1,0,0},
	{0,0,0,1,0},
	{0,0,0,0,1},
	{1,2,1,1,1}};
void cal(ll b[5][5])
{
	ll tmp2[5][5];
	for(int i=0;i<5;++i)
    {
    	for(int j=0;j<5;++j)
        {
        	tmp[i][j]=0;
        	for(int k=0;k<5;k++)
        	{
        		tmp[i][j]=(tmp[i][j]+ar[i][k]*b[k][j])%MOD;
            }
        }
    }
    for(int i=0;i<5;++i)
    {
    	for(int j=0;j<5;++j)
    	{
    		ar[i][j]=tmp[i][j];
    	}
    }
}
void solve(ll n)
{
	if(n<2)
		return;
	solve(n>>1);
	cal(ar);
	if(n&1)
		cal(tmp);
}*/
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a[5],n;
		scanf("%lld %lld %lld %lld %lld %lld",&a[0],&a[1],&a[2],&a[3],&a[4],&n);
		if(n<5)
		{
			printf("%lld\n",a[n]);
		}
		else
		{
			/*ar[0][0]=0, ar[0][1]=1, ar[0][2]=0, ar[0][3]=0, ar[0][4]=0;
			ar[1][0]=0, ar[1][1]=0, ar[1][2]=1, ar[1][3]=0, ar[1][4]=0;
			ar[2][0]=0, ar[2][1]=0, ar[2][2]=0, ar[2][3]=1, ar[2][4]=0;
			ar[3][0]=0, ar[3][1]=0, ar[3][2]=0, ar[3][3]=0, ar[3][4]=1;
			ar[4][0]=1, ar[4][1]=2, ar[4][2]=1, ar[4][3]=1, ar[4][4]=1;
/*		ar[5][5]={
			{0LL,1LL,0LL,0LL,0LL},
			{0LL,0LL,1LL,0LL,0LL},
			{0LL,0LL,0LL,1LL,0LL},
			{0LL,0LL,0LL,0LL,1LL},
			{1LL,2LL,1LL,1LL,1LL}};*/
			ll ans=solve(n+1, a);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
