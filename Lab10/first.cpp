#include <bits/stdc++.h>
using namespace std;
#define MP make_pair

long long find(long long rank[],long long x)
{
  if(rank[x]==x)return x;
  else return rank[x]=find(rank,rank[x]);
}

void un(long long rank[], long long size[], long long x, long long y)
{
  x=find(rank,x);
  y=find(rank,y);

  if(x==y)return;
  if(size[x]>size[y])swap(x,y);
  rank[x]=y;
  size[y]+=size[x];
}

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    map<pair<long long,long long>,long long>val;
    long long rank[k],size[k],x[k],y[k];
    for(long long i=0;i<k;i++)
    {
      cin>>x[i]>>y[i];
      rank[i]=i;
      size[i]=1;
      val[MP(x[i],y[i])]=i;
    }
    for(long long i=0;i<k;i++)
    {
      if(val.count(MP(x[i]-1,y[i])) !=0)un(rank, size, i, val[MP(x[i]-1,y[i])]);
      if(val.count(MP(x[i],y[i]+1)) !=0)un(rank, size, i, val[MP(x[i],y[i]+1)]);
      if(val.count(MP(x[i],y[i]-1)) !=0)un(rank, size, i, val[MP(x[i],y[i]-1)]);
      if(val.count(MP(x[i]+1,y[i])) !=0)un(rank, size, i, val[MP(x[i]+1,y[i])]);
    }
    long long ans=0;
    for(long long i=0;i<k;i++)ans=max(ans,size[i]);
    cout<<ans<<endl;
    return 0;
}
