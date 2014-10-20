/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/*Convex Hull*/
struct Point
{
	ll x,y;
};
Point p;
int orientation(Point p1, Point p2, Point p3)
{
	int val=(p2.y-p1.y)*(p3.x-p2.x)-(p2.x-p1.x)*(p3.y-p2.y);
	if(val==0)
		return 0;
	if(val>0)
		return 1;
	return 2;
}
ll comp_dist(Point p1, Point p2)
{
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int compare(const void* a, const void* b)
{
	Point *p1=(Point *)a;
	Point *p2=(Point *)b;
	int orx=orientation(p,*p1,*p2);
	if(orx==0)
		return comp_dist(p,*p2)>=comp_dist(p,*p1)?-1:1;
	return orx==2?-1:1;
}
void convexHull(Point pts[], int n)
{
	ll miny=pts[0].y, ind=0;
	for(int i=1;i<n;++i)
	{
		if(pts[i].y < miny || (miny==pts[i].y && pts[i].x<pts[ind].x))
		{
			miny=pts[i].y;
			ind=i;
		}
	}
	swap(pts[0],pts[ind]);
	p=pts[0];
	qsort(&pts[1],n-1,sizeof(Point), compare);
	//sort(pts.begin(),pts.end(),cmp);
	stack<Point> s;
	s.push(pts[0]);
	s.push(pts[1]);
	s.push(pts[2]);
	for(int i=3;i<n;++i)
	{
		while(true)
		{
			if(s.empty())
				break;
			Point tmp=s.top();
			s.pop();
			if(s.empty())
			{
				s.push(tmp);
				break;
			}
			Point sec=s.top();
			s.push(tmp);
			if(orientation(sec,s.top(),pts[i])==2)
				break;
			s.pop();
		}
	}
	vector<Point> ans;
	while(!s.empty())
	{
		assert(!s.empty());
		ans.push_back(s.top());
		s.pop();
	}
	double maxx=0,final_ans=0;
	for(int i=0;i<ans.size()-1;++i)
	{
		double tmp=sqrt(comp_dist(ans[i],ans[i+1]));
		if(tmp>maxx)
			maxx=tmp;
		final_ans+=tmp;
	}
	double tmp=sqrt(comp_dist(ans[ans.size()-1],ans[0]));
	if(tmp>maxx)
		maxx=tmp;
	final_ans+=tmp;
	final_ans-=maxx;
	printf("%0.2lf\n",final_ans);
}
Point v[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		Point tmp;
		int n;
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>v[i].x>>v[i].y;
		if(n==1)
			cout<<"0.00\n";
		else if(n==2)
		{
			printf("%.2lf\n",sqrt(comp_dist(v[0],v[1])));
		}
		else
			convexHull(v,n);
	}
	return 0;
}
