/*
ID: ashish1610
PROG: Distinct Digits 2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define MAX 400005
#define ll	long long int
#define MOD	1000000007
ll arr[N];
ll tree[MAX][20];
inline int dis_dig(ll n)
{
	set<int> s;
	int rem;
	while(n!=0)
	{
		rem=n%10;
		s.insert(rem);
		n/=10;
	}
	return s.size();
}
inline void build_tree(int node, int a, int b) 
{
	if(a > b)
		return;
	if(a == b) 
	{
		for(int i=1;i<=18;++i)
			tree[node][i]=0;
		tree[node][dis_dig(arr[a])]=1;
		return;
	}
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	for(int i=1;i<=18;++i)
		tree[node][i]+=tree[2*node][i]+tree[2*node+1][i];
}
inline void update_tree(int node, int a, int b, int i, ll value, int type)
{
	if(a==b)
	{
		if(type==0)
		{
			arr[a]=(arr[a]+value);
			for(int j=1;j<=18;++j)
				tree[node][j]=0;
			tree[node][dis_dig(arr[a])]=1;
		}
		else if(type==1)
		{
			arr[a]=(value);
			for(int j=1;j<=18;++j)
				tree[node][j]=0;
			tree[node][dis_dig(arr[a])]=1;
		}
		return;
	}
	int mid=(a+b)/2;
	if(i<=mid)
		update_tree(2*node,a,mid,i,value,type);
	else
		update_tree(2*node+1,mid+1,b,i,value,type);
	for(int j=1;j<=18;++j)
		tree[node][j]=(tree[2*node][j]+tree[2*node+1][j]);
}
inline int query_tree(int node, int a, int b, int i, int j, int c)
{
	if(a>b || a>j || b<i)
		return -1;
	if(a>=i && b<=j)
		return tree[node][c];
	int mid=(a+b)/2;
	int p1=query_tree(node*2, a, mid, i, j, c);
	int p2=query_tree(node*2+1, mid+1, b, i, j, c);
	if(p1==-1)
		return p2;
	if(p2==-1)
		return p1;
	return p1+p2;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",&arr[i]);
	build_tree(1,0,n-1);
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		ll l,r;
		int type;
		cin>>type;
		scanf("%lld %lld",&l,&r);
		l--;
		if(type==0)
			update_tree(1,0,n-1,l,r,0);
		else if(type==1)
			update_tree(1,0,n-1,l,r,1);
		else
		{
			int c;
			cin>>c;
			if(c==0)
				printf("0\n");
			else
			{
				r--;
				int ans=query_tree(1,0,n-1,l,r,c);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
