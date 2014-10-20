/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MAX = 1005;
const int MAXINT = INT_MAX;
int n;
vvii G(MAX);
vi ans[1005];
vector<int> Dijkstra(int s)
{
	vi D(MAX,MAXINT);
    set<ii> Q;
    D[s] = 0;
    Q.insert(ii(0,s));
    while(!Q.empty())
    {
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        int d = top.first;
 
        for (vii::const_iterator it = G[v].begin(); it != G[v].end(); it++)
        {
            int v2 = it->first;
            int cost = it->second;
            if (D[v2] > D[v] + cost)
            {
                if (D[v2] != INT_MAX)
                {
                    Q.erase(Q.find(ii(D[v2], v2)));
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2], v2));
            }
        }
    }
    return D;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int m,q,l,x,y;
	cin>>n>>m>>q>>l;
	for(int i=0;i<m;++i)
	{
		cin>>x>>y;
		G[x-1].push_back(ii(y-1, l));
        G[y-1].push_back(ii(x-1, l));
	}
	for(int i=0;i<n;++i)
	{
		vector<int> tmp=Dijkstra(i);
		for(int j=0;j<n;++j)
			ans[i].push_back(tmp[j]);
	}
	/*for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}*/
	while(q--)
	{
		cin>>x>>y;
		ll finalans=ans[x-1][y-1];
		if(finalans==INT_MAX)
			cout<<"not possible\n";
		else
		{
			cout<<finalans<<endl;
		}
	}
	return 0;
}
