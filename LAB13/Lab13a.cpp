#include<bits/stdc++.h>
using namespace std;
string reverse(string str)
{
	string temp;
	temp.resize(str.size());
	for(int i=0;i<str.size();i++)
	{
		temp[i]=str[str.size()-i-1];

	}
	return temp;
}

int main()
{
	set<string> words;
	int flag=0;
	int n;
	cin>>n;
	string temp,temp2;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		temp2=reverse(temp);
		if(temp==temp2)
		{
			 continue;
		}
		else
		{
			//cout<<" "<<reverse(temp)<<endl;
			if( words.find(temp2) != words.end() )
			{
				flag=1;

			}
			else
			{
				words.insert(temp);
			}

		}

	}
	
	if(flag==0)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
	
	cout<<endl;
	return 0;
}
