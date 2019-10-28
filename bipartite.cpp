#include<bits/stdc++.h>
using namespace std;
int dfs(int v,vector<int>&color,vector<int>adj[])
{
	//cout<<"DFS: "<<v<<endl;
	for(int i=0;i<adj[v].size();i++)
	{
		if(color[adj[v][i]]==-1)
		{
			//cout<<color[v];
			color[adj[v][i]]=1-color[v];
			//cout<<"HERE";
			if(dfs(adj[v][i],color,adj)==-1)
			{

				return -1;
			}
		}
		else if(color[adj[v][i]]==color[v])
		{
			return -1;
		}
		else if(color[adj[v][i]]==1-color[v])
		{
			continue;
		}
	}
	return  0;
}
int main()
{
	int n,m;	
	cin>>n>>m;
	vector<int>color(n+1,-1);
	vector<int>adj[n+1];
	for(int i=1;i<=n;i++)
	{
		assert(color[i]=-1);
	}
	int u,v;

	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{	
		if(color[i]==-1)
		{	color[i]=0;
			if(dfs(i,color,adj)==-1)
			{
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"YES"<<endl;
	}
/*
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" : ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<color[i]<<" ";
	}
*/
	return 0;
}