/*
ID: ashish1610
PROG: 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>comp[1005];
int adj[1005][1005];
bool visited[1005];
int dis[1005];
int main()
{
	for(int i=0;i<1005;++i)
		for(int j=0;j<1005;++j)
			adj[i][j]=0;
	//memset(adj,0,sizeof(adj));
	int n,m,a,b,u,v;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	for(int i=0;i<m;++i)
	{
		scanf("%d %d",&u,&v);
		adj[u][v]=1;
		adj[v][u]=1;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(adj[i][j]==0 && i!=j)
			{
				comp[i].push_back(j);
				comp[j].push_back(i);
			}
		}
	}
	for(int i=0;i<=n;++i)
		dis[i]=INT_MAX;
	//memset(dis,0,sizeof(dis));
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(a);
	//int ans=0;
	dis[a]=0;
	visited[a]=true;
	while(!q.empty() && !visited[b])
	{
		int nd=q.front();
		q.pop();
		//if(nd!=b)
		//	ans++;
		for(int i=0;i<comp[nd].size();++i)
		{
			if(!visited[comp[nd][i]])
			{
				visited[comp[nd][i]]=true;
				q.push(comp[nd][i]);
				dis[comp[nd][i]]=dis[nd]+1;
			}
		}
	}
	if(!visited[b] || dis[b]==INT_MAX)
		printf("-1\n");
	else
		printf("%d\n",dis[b]);
	return 0;
}
