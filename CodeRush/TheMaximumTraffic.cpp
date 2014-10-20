/*
ID: ashish1610
PROG: The Maximum Traffic
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll ar[100005];
ll tree[400005];
ll lazy[400005];
void build_tree(int node, int a, int b)
{
	if(a>b)
		return;
	if(a==b) 
	{
		tree[node]=ar[a];
		return;
	}
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}
void update_tree(int node, int a, int b, int i, int j, int value) 
{
	if(lazy[node]!=0) 
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(a>b || a>j || b<i)
		return;
	if(a>=i && b<=j)
	{
		tree[node]+=value;
		if(a!=b)
		{
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
		return;
	}
	update_tree(node*2, a, (a+b)/2, i, j, value);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}
ll query_tree(int node, int a, int b, int i, int j)
{
	if(a>b || a>j || b<i) return -LONG_MAX;
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>=i && b<=j)
		return tree[node];
	ll q1 = query_tree(node*2, a, (a+b)/2, i, j);
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
	return max(q1,q2);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll p, q;
		scanf("%lld %lld",&p,&q);
		for(int i=0;i<p;++i)
			ar[i]=0;
		build_tree(1,0,p-1);
		memset(lazy,0,sizeof(lazy));
		while(q--)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			update_tree(1,0,p-1,b-1,a+b-2,1);
		}
		printf("%lld\n",query_tree(1,0,p-1,0,p-1));
	}
	return 0;
}
