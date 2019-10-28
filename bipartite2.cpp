#include<bits/stdc++.h>
using namespace std;
int dfs(int v,vector<int>&color,vector<int>adj[])
{
	cout<<"DFS: "<<v<<endl;
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
	vector<int>adj[n+m+1];
	vector<int>color(n+m+1,-1);
	//vector<int>wt[n+1];
	int u,v,w;
	int ctr=n+1;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		if(w%2==0)
		{
			adj[ctr].push_back(u);
			//cout<<u<<" pushed on to "<<ctr<<endl;
			adj[u].push_back(ctr);
			//cout<<ctr<<" pushed on to "<<u<<endl;
			adj[ctr].push_back(v);
			//cout<<v<<" pushed on to "<<ctr<<endl;
			adj[v].push_back(ctr);
			//cout<<ctr<<" pushed on to "<<v<<endl;
			ctr++;
		}
		else      
		{
			//cout<<"ELSE"<<endl;
		adj[u].push_back(v);
		//cout<<v<<" pushed on to "<<u<<endl;
		adj[v].push_back(u);
		//cout<<u<<" pushed on to "<<v<<endl;

		}
		
	}
	/*
	for(int i=1;i<ctr;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	*/

	int flag=0;
	for(int i=1;i<=n;i++)
	{	
		if(color[i]==-1)
		{	color[i]=0;
			if(dfs(i,color,adj)==-1)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"NO"<<endl;
	}


	return 0;
}