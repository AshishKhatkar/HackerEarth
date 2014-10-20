/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int tree[1000005];
int query(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=tree[idx];
		idx-=(idx&(-idx));
	}
	return sum;
}
void update(int idx, int val, int lim)
{
	lim++;
	while(idx<=lim)
	{
		tree[idx]+=val;
		idx+=(idx&(-idx));
	}
}
char str[500005][15];
int ar[500005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%s",str[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&ar[i]);
		memset(tree,0,sizeof(tree));
		int tree_sz=log2(n);
		tree_sz=1<<(tree_sz+1);
		for(int i=1;i<=tree_sz;++i)
			update(i,1,tree_sz);
		int tmp,max_so_far=0;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d",&tmp);
			int high=tree_sz, ind=0, ind_ans;
			while(high && ind<n)
			{
				if(tmp==tree[ind+high])
					ind_ans=ind+high;
				else if(tmp>tree[ind+high])
				{
					tmp-=tree[ind+high];
					ind+=high;
				}
				high>>=1;
			}
			update(ind_ans,-1,tree_sz);
			max_so_far=max(max_so_far,ar[ind_ans-1]);
			printf("%s %d\n",str[ind_ans-1],max_so_far);
		}
		tmp=1;
		int high=tree_sz, ind=0, ind_ans;
		while(high && ind<n)
		{
			if(tmp==tree[ind+high])
				ind_ans=ind+high;
			else if(tmp>tree[ind+high])
			{
				tmp-=tree[ind+high];
				ind+=high;
			}
			high>>=1;
		}
		update(ind_ans,-1,tree_sz);
		max_so_far=max(max_so_far,ar[ind_ans-1]);
		printf("%s %d\n",str[ind_ans-1],max_so_far);
	}
	return 0;
}
