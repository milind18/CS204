#include<bits/stdc++.h>

using namespace std;
const int z=(int)('0');

void prnt(string s)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        cout<<s[i];
    }

}
char chr(int a)
{
    return (char)(a+z);
}
int num(char a)
{
    return (int)(a)-(int)('0');
}
string trim(string a)
{
    int flag=0;  //To check if the input is zero.
    int lz=0;  //Number of leading zeroes.
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')
           {
               lz++;
               continue;

           }
        else
        {flag=1;
          break;
        }
    }
    if(flag==0)
    {
        return "0";
    }
    for(int i=lz;i<a.size();i++)
    {
        a[i-lz]=a[i];
    }
    a.resize(a.size()-lz);
    return a;
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
string smulti(string a,char b)
{
    string result;
    result.resize(a.size());
    reverse(a.begin(),a.end());
    int sum;
    int car=0;
    int n=num(b);
    for(int i=0;i<a.size();i++)
    {
       sum=n*num(a[i])+car;
       car=sum/10;
       sum=sum%10;
       result[i]=chr(sum);
    }
    if(car!=0)
    {
        result.resize(result.size()+1,chr(car));
    }
    return result;
}
string multi(string a,string b)
{
    string result;
    result.resize(a.size()+b.size()+1,'0');
   // reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string sm;
    for(int i=0;i<b.size();i++)
    {
        sm.resize(a.size()+1);
        sm=smulti(a,b[i]);
        reverse(sm.begin(),sm.end());
        sm.resize(sm.size()+i,'0');
        result=sum(result,sm);
        reverse(result.begin(),result.end());
    }
    return trim(result);
}
int main()
{
string a,b;
int t;
cin>>t;
while(t--)
{
cin>>a>>b;
cout<<(multi(a,b))<<endl;
}

return 0;

}
