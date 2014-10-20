/*
ID: ashish1610
PROG: Hungarian Algorithm
LANG: C++
Algorithm learned from TopCoder and this code taken from TopCoder
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1000000007
int cost[105][105];
int n, max_match;
int lx[105], ly[105];
int xy[105];
int yx[105];
bool S[105], T[105];
int slack[105];
int slackx[105];
int prv[105];
void init_labels()
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            lx[i]=max(lx[i],cost[i][j]);
}
void update_labels()
{
    int x,y,delta=INF;
    for(int i=0;i<n;++i)
        if(!T[i])
            delta=min(delta,slack[i]);
    for(int i=0;i<n;++i)
        if(S[i])
            lx[i]-=delta;
    for(int i=0;i<n;++i)
        if(T[i])
            ly[i]+=delta;
    for(int i=0;i<n;++i)
        if(!T[i])
            slack[i]-=delta;
}
void add_to_tree(int x, int prvx) 
{
    S[x]=true;
    prv[x]=prvx;
    for(int i=0;i<n;++i)
    {
        if(lx[x]+ly[i]-cost[x][i]<slack[i])
        {
            slack[i]=lx[x]+ly[i]-cost[x][i];
            slackx[i]=x;
        }
    }
}
void augment()
{
    if(max_match==n)
        return;
    int x, y, root;
    int q[105], wr = 0, rd = 0;
    memset(S,false,sizeof(S));
    memset(T,false,sizeof(T));
    memset(prv,-1,sizeof(prv));
    for(x=0;x<n;++x)
    {
        if(xy[x]==-1)
        {
            q[wr++]=root=x;
            prv[x]=-2;
            S[x]=true;
            break;
        }
    }
    for(y=0;y<n;++y)
    {
        slack[y]=lx[root]+ly[y]-cost[root][y];
        slackx[y]=root;
    }
    while(true)
    {
        while(rd<wr)
        {
            x=q[rd++];
            for(y=0;y<n;++y)
            {
                if((cost[x][y]==lx[x]+ly[y])&&!T[y])
                {
                    if(yx[y]==-1)
                        break;
                    T[y]=true;
                    q[wr++]=yx[y];
                    add_to_tree(yx[y],x);
                }
            }
            if(y<n)
                break;
        }
        if(y<n)
            break;
        update_labels();
        wr=rd=0;
        for(y=0;y<n;++y)
        {
            if(!T[y]&&(slack[y]==0))
            {
                if(yx[y]==-1)
                {
                    x=slackx[y];
                    break;
                }
                else
                {
                    T[y]=true;
                    if(!S[yx[y]])
                    {
                        q[wr++]=yx[y];
                        add_to_tree(yx[y], slackx[y]);
                    }
                }
            }
        }
        if(y<n)
            break;
    }
    if(y<n)
    {
        max_match++;
        for(int cx=x,cy=y,ty;cx!=-2;cx=prv[cx],cy=ty)
        {
            ty=xy[cx];
            yx[cy]=cx;
            xy[cx]=cy;
        }
        augment();
    }
}
int hungarian()
{
    int ret=0;
    max_match=0;
    memset(xy,-1,sizeof(xy));
    memset(yx,-1,sizeof(yx));
    init_labels();
    augment();
    for (int x=0;x<n;++x)
        ret+=cost[x][xy[x]];
    return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
    	scanf("%d",&n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&cost[i][j]);
    	printf("%d\n",hungarian());
	}
	return 0;
}
