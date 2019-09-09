#include<bits/stdc++.h>
using namespace std;
int comp(string a, string b)
{
	string x=a;
	string y=b;
	x.append(b);
	y.append(a);
	
	for(int i=0;i<x.size();i++)
	{
		if(x[i]>y[i])
			return 1;
		else if(x[i]<y[i])
			return -1;
		
	}
	return 1;
}


void merge(vector<string>&arr,int l,int r)
{

	int mid=(l+r)/2;
	vector<string>a;
	vector<string>b;
	for(int i=l;i<=mid;i++)
	{
		a.push_back(arr[i]);
	}
	for(int i=mid+1;i<=r;i++)
	{
		b.push_back(arr[i]);
	}

	a.push_back("inf");
	b.push_back("inf");

	int x=l;
	int y=mid+1;
	int ctr=l-1;
	
	while(ctr!=r)
	{
		
		
		if(comp(a[x-l],b[y-mid-1])==-1)
		{	
			ctr++;
			arr[ctr]=a[x-l];
			x++;
		}
		else
		{	
			ctr++;
			arr[ctr]=b[y-mid-1];
			y++;
		}

	}

	
}


void merge_sort(vector<string>&input,int l,int r)
{
	if(l==r)
	{
		return ;
	}
	else
	{
		int mid=(l+r)/2;
		merge_sort(input,l,mid);
		merge_sort(input,mid+1,r);
		merge(input,l,r);
	}
}
int main()
{
int t;
cin>>t;
while(t--)
{
	vector<string>input;
	int n;
	cin>>n;
	string temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	merge_sort(input,0,input.size()-1);
	for(int i=input.size()-1;i>=0;i--)
	{
		cout<<input[i];
	}
cout<<endl;



}


	return 0;
}
