#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	stack<char>s;
	s.push('0');

	int q;
	cin>>q;


	char arr[5][2]={'(',')',
					'{','}',
					'<','>',
					'|','|',
					'[',']'};

	/*for(int i=0;i<5;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	*/

	bool flag,flag2;
	
	while(q--)
	{
		while(s.top()!='0')
		{
			s.pop();
		}


		flag=true;
		


		cin>>a;


		for(int i=0;i<a.size();i++)
		{

			flag2=false;
			for(int j=0;j<5;j++)
			{



				if(arr[j][0]==a[i])
					{
						if(j==3 && s.top()=='|')
						{							
							break;
						}

						s.push(a[i]);
						flag2=true;
						break;
					}




			}


			if(flag2!=true)
			{
				int j=0;
				
				for(;j<5;j++)
				{
					if(arr[j][1]==a[i])
						break;
				}
			
				
				if(s.top()==arr[j][0])
				{
					s.pop();
				}

				else
				{
					flag=false;
					break;
				}

			}
		}



		if(flag==false)
		{
			cout<<"NO"<<endl;
			
		}

		

		if(flag==true&&s.top()=='0')
		{
			cout<<"YES"<<endl;
		}
		else
		{
			if(flag==true)
			{
				cout<<"NO"<<endl;
			}
		}
	}
	

	return 0;
}
