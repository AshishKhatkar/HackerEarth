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
ll tree[MAX][4];
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
		tree[node][0]=dis_dig(arr[a]);
		tree[node][1]=tree[node][0];
		tree[node][2]=1;
		tree[node][3]=1;
		return;
	}
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	if(tree[node*2][0]==tree[node*2+1][0])
	{
		tree[node][0]=tree[node*2][0];
		tree[node][2]=tree[node*2][2]+tree[node*2+1][2];
	}
	else if(tree[node*2][0]>tree[node*2+1][0])
	{
		tree[node][0]=tree[node*2][0];
		tree[node][2]=tree[node*2][2];	
	}
	else
	{
		tree[node][0]=tree[node*2+1][0];
		tree[node][2]=tree[node*2+1][2];
	}
	if(tree[node*2][1]==tree[node*2+1][1])
	{
		tree[node][1]=tree[node*2][1];
		tree[node][3]=tree[node*2][3]+tree[node*2+1][3];
	}
	else if(tree[node*2][1]>tree[node*2+1][1])
	{
		tree[node][1]=tree[node*2+1][1];
		tree[node][3]=tree[node*2+1][3];	
	}
	else
	{
		tree[node][1]=tree[node*2][1];
		tree[node][3]=tree[node*2][3];
	}
}
inline void update_tree(int node, int a, int b, int i, ll value, int type)
{
	if(a==b)
	{
		if(type==1)
		{
			arr[a]=(arr[a]+value)%MOD;
			tree[node][0]=dis_dig(arr[a]);
			tree[node][1]=tree[node][0];
		}
		else if(type==2)
		{
			arr[a]=(arr[a]*value)%MOD;
			tree[node][0]=dis_dig(arr[a]);
			tree[node][1]=tree[node][0];
		}
		else
		{
			arr[a]=value%MOD;
			tree[node][0]=dis_dig(arr[a]);
			tree[node][1]=tree[node][0];
		}
		return;
	}
	int mid=(a+b)/2;
	if(i<=mid)
		update_tree(2*node,a,mid,i,value,type);
	else
		update_tree(2*node+1,mid+1,b,i,value,type);
	if(tree[node*2][0]==tree[node*2+1][0])
	{
		tree[node][0]=tree[node*2][0];
		tree[node][2]=tree[node*2][2]+tree[node*2+1][2];
	}
	else if(tree[node*2][0]>tree[node*2+1][0])
	{
		tree[node][0]=tree[node*2][0];
		tree[node][2]=tree[node*2][2];	
	}
	else
	{
		tree[node][0]=tree[node*2+1][0];
		tree[node][2]=tree[node*2+1][2];
	}
	if(tree[node*2][1]==tree[node*2+1][1])
	{
		tree[node][1]=tree[node*2][1];
		tree[node][3]=tree[node*2][3]+tree[node*2+1][3];
	}
	else if(tree[node*2][1]>tree[node*2+1][1])
	{
		tree[node][1]=tree[node*2+1][1];
		tree[node][3]=tree[node*2+1][3];	
	}
	else
	{
		tree[node][1]=tree[node*2][1];
		tree[node][3]=tree[node*2][3];
	}
}
inline pair<int,int> query_tree(int node, int a, int b, int i, int j, int type)
{
	if(type==1)
	{
		if(a>b || a>j || b<i)
			return make_pair(0,0);
		if(a>=i && b<=j)
			return make_pair(tree[node][0],tree[node][2]);
		int mid=(a+b)/2;
		pair<int,int> p1=query_tree(node*2, a, mid, i, j, type);
		pair<int,int> p2=query_tree(node*2+1, mid+1, b, i, j, type);
		if(p1.first==p2.first)
		{
			p1.second+=p2.second;
			return p1;
		}
		else if(p1.first>p2.first)
			return p1;
		else
			return p2;
	}
	else
	{
		if(a>b || a>j || b<i)
			return make_pair(1000000000,1000000000);
		if(a>=i && b<=j)
			return make_pair(tree[node][1],tree[node][3]);
		int mid=(a+b)/2;
		pair<int,int> p1=query_tree(node*2, a, mid, i, j, type);
		pair<int,int> p2=query_tree(node*2+1, mid+1, b, i, j, type);
		if(p1.first==p2.first)
		{
			p1.second+=p2.second;
			return p1;
		}
		else if(p1.first>p2.first)
			return p2;
		else
			return p1;
	}
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
		string type;
		cin>>type;
		scanf("%lld %lld",&l,&r);
		l--;
		if(type=="ADD")
			update_tree(1,0,n-1,l,r,1);
		else if(type=="MUL")
			update_tree(1,0,n-1,l,r,2);
		else if(type=="REP")
			update_tree(1,0,n-1,l,r,3);
		else if(type=="MAX")
		{
			r--;
			pair<int,int> ans=query_tree(1,0,n-1,l,r,1);
			printf("%d %d\n",ans.first,ans.second);
		}
		else
		{
			r--;
			pair<int,int> ans=query_tree(1,0,n-1,l,r,2);
			printf("%d %d\n",ans.first,ans.second);
		}
	}
	return 0;
}
