#include<bits/stdc++.h>
using namespace std;
class UnionFind 
{
public:
    UnionFind(int n) 
   	{
        size = n;
        sets = new int[size];
        rank = new int[size];
        for(int i=0; i < size; i++)
        {
            sets[i] = i; rank[i] = 0;
        }
    }

    ~UnionFind()
    {
        delete [] sets;
        delete [] rank;
    }
    
    int find(int s) 
    {
        assert(s >= 0 && s < size);
        vector<int> A;
        while(s != sets[s])
        {
            A.push_back(s);
            s = sets[s];
        }
        for(int i=0; i < A.size(); i++) 
        	sets[A[i]] = s;
        return s;
    }
    bool merge(int s1, int s2) 
    {
        assert(s1 >= 0 && s1 < size);
        assert(s2 >= 0 && s2 < size);
        int s1_rep = find(s1);

        int s2_rep = find(s2);

        if(s1_rep == s2_rep) return false;

        if(rank[s1_rep] > rank[s2_rep])
        {
            sets[s2_rep] = s1_rep;
        }
        else if(rank[s1_rep] < rank[s2_rep])
        {
            sets[s1_rep] = s2_rep;
        } 
        else 
        {    
            sets[s2_rep] = s1_rep;
            rank[s1_rep] += 1;
        }

        return true;    
    }
    void print_sets()
    {
        for(int i=0; i < size; i++) cout << find(i) << " ";
        cout << endl;
    }
private:
    int size = 0;
    int* sets;  
    int* rank;
};

struct edge
{
	int u;
	int v;
	long double w;
};
bool compare(edge a,edge b)
{
	if(a.w>b.w)
		return true;
	else
		return false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<edge>edges(m);
	int u,v,w;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		edges[i].u=u;
		edges[i].v=v;
		edges[i].w=w;

	}
	sort(edges.begin(),edges.end(),compare);
	for(int i=0;i<edges.size();i++)
	{
		cout<<edges[i].w<<endl;
	}

	UnionFind connect(n);
	long double ans=0;
	int count=0;

	for(int i=0;i<edges.size();i++)
	{
		if(connect.find(edges[i].u)==connect.find(edges[i].v))
		{
			continue;
		}
		else
		{
			ans+=edges[i].w;
			connect.merge(edges[i].v,edges[i].u);
			count++;
		}
	}
	connect.print_sets();
	cout<<count;

	return 0;
}
