#include<bits/stdc++.h>

using namespace std;
const int z=(int)('0');
void prnt(string s)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<endl;
}
char chr(int a)
{
    return (char)(a+z);
}
int num(char a)
{
    return (int)(a)-(int)('0');
}

string sum(string a,string b)
{
    string result;
    int s;
    int c=0;


    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.size()>b.size())
    {
        b.resize(a.size(),'0');
    }
    else
    {
        if(a.size()<b.size())
        {
            a.resize(b.size(),'0');
        }

    }

    result.resize(a.size());
    for(int i=0;i<a.size();i++)
    {

        s=num(a[i])+num(b[i])+c;
        c=s/10;
        s=s%10;
        result[i]=chr(s);
    }
    if(c==1)
    {
           result.append("1");
    }
  return result;
}
int main()
{
string a,b;
int t;
cin>>t;
while(t--)
{
cin>>a>>b;
prnt(sum(a,b));

}
return 0;
}
