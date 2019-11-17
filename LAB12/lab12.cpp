#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define V(a) vector<a>

ll fn(ll x,ll rn[])
{
    if(x==rn[x]) return x;
    else return rn[x]=fn(rn[x],rn);
}

ll un(ll x,ll y,ll rn[],ll sz[])
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y) return false;
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    rn[y]=x;
    return true;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>> v;
    REP(i,0,m)
    {
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        t1--;t2--;
        v.PB(MP(t3,MP(t1,t2)));
    }
    sort(v.begin(),v.end());
    ll ans=1;
    ll rn[n];
    ll sz[n];
    REP(i,0,n)
    {
        rn[i]=i;
        sz[i]=1;
    }
    REPI(i,0,m)
    {
        if(un((v[i].S).F,(v[i].S).S,rn,sz)) ans*=(v[i].F)%M;
        ans%=M;
    }
    cout<<ans;

    return 0;
}
