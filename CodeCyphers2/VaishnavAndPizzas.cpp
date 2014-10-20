/*
ID: ashish1610
PROG: Vaishnav and Pizzas
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll ans[10005];
ll totient(int n)
{
    ll i, ans=n;
    for (i=2;i*i<=n;++i)
    {
        if(n%i==0)
            ans-=ans/i;       
        while(n%i==0)
            n/=i;
    }
    if(n!=1)
        ans-=ans/n;
    return ans;    
}
void pre_compute()
{
	ans[0]=0;
	ans[1]=1;
	for(int i=2;i<=10000;++i)
		ans[i]=ans[i-1]+totient(i);
}
int main()
{
	pre_compute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]-1);
	}
	return 0;
}
