/*
ID: ashish1610
Pans2OG: Super Powers of 2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define MOD 1000000007
ll ar[200005],pw[200005],ar2[4*200005],ar1[4*200005];
bool flag[4*200005];
void pre_compute(ll n)
{
    pw[0]=1;
    for(ll i=1;i<=n;++i)
        pw[i]=(2*pw[i-1])%MOD;
    for(ll i=1;i<=n;++i)
        pw[i]=(pw[i]+pw[i-1])%MOD;
}
void tree_update(ll node, ll lt, ll rt, ll l, ll r)
{
    if(flag[node])
    {
        ar2[node]=(ar2[node]+(ar1[node]*pw[rt-lt])%MOD)%MOD;
        ll mid=(lt+rt)/2;
        ll lft=2*node+1;
        ll rgt=2*node+2;
        if(lt!=rt)
        {
            ar1[lft]=(ar1[lft]+ar1[node])%MOD;
            ar1[rgt]=(ar1[rgt]+(ar1[node]*(pw[mid-lt+1]-pw[mid-lt]+MOD))%MOD)%MOD;
            flag[lft]=true;
            flag[rgt]=true;
        }
        flag[node]=false;
        ar1[node]=0;
    }
    if(r<lt || l>rt)
        return;
    ll mid=(lt+rt)/2;
    ll lft=2*node+1;
    ll rgt=2*node+2;
    if(l<=lt && rt<=r)
    {
        ar2[node]=(ar2[node]+pw[rt-l+1]-pw[lt-l]+MOD)%MOD;
        if(lt!=rt)
        {
            ar1[lft]=(ar1[lft]+pw[lt-l+1]-pw[lt-l]+MOD)%MOD;
            ar1[rgt]=(ar1[rgt]+pw[mid-l+2]-pw[mid-l+1]+MOD)%MOD;
            flag[lft]=true;
            flag[rgt]=true;
        }
        return;
    }
    tree_update(lft,lt,mid,l,r);
    tree_update(rgt,mid+1,rt,l,r);
    ar2[node]=(ar2[lft]+ar2[rgt])%MOD; 
}
ll query_tree(ll node, ll lt, ll rt, ll l, ll r)
{
    if(flag[node])
    {
        ar2[node]=(ar2[node]+(ar1[node]*pw[rt-lt])%MOD)%MOD;
        ll mid=(lt+rt)/2;
        ll lft=2*node+1;
        ll rgt=2*node+2;
        if(lt!=rt)
        {
            ar1[lft]=(ar1[lft]+ar1[node])%MOD;
            ar1[rgt]=(ar1[rgt]+(ar1[node]*(pw[mid-lt+1]-pw[mid-lt]+MOD))%MOD)%MOD;
            flag[lft]=true;
            flag[rgt]=true;
        }
        flag[node]=false;
        ar1[node]=0;
    }
    if(l>rt||r<lt)
        return 0;
    if(l<=lt && rt<=r)
        return ar2[node]%MOD;
    ll mid=(lt+rt)/2;
    ll lft=2*node+1;
    ll rgt=2*node+2;
    ll ans1=query_tree(lft,lt,mid,l,r);
    ll ans2=query_tree(rgt,mid+1,rt,l,r);
    return (ans1+ans2)%MOD;
}
int main()
{
    memset(ar,0,sizeof(ar));
    memset(ar1,0,sizeof(ar1));
    memset(ar2,0,sizeof(ar2));
    memset(pw,0,sizeof(pw));
    memset(flag,false,sizeof(flag));
    ll n,tmp,q;
    scanf("%lld",&n);
    pre_compute(n);
    for(ll i=1;i<=n;++i)
    {
        scanf("%lld",&tmp);
        ar[i]=(tmp+ar[i-1])%MOD;
    }
    scanf("%lld",&q);
    while(q--)
    {
        ll type, l, r;
        scanf("%lld %lld %lld",&type,&l,&r);
        l--;
        r--;
        if(type==0)
            tree_update(0,0,n-1,l,r);
        else
        {
            ll ans1=query_tree(0,0,n-1,l,r)%MOD;
            ll ans2=(ar[r+1]-ar[l]+MOD)%MOD;
            printf("%lld\n",(ans1+ans2)%MOD);
        }
    }
    return 0;
}
