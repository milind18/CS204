#include<bits/stdc++.h>

using namespace std;
const int z=(int)('0');

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
int larger(string x,string y)
{

    string a=trim(x);
    string b=trim(y);

    if(a.size()>b.size())
    {

        return 1;
    }
    else
    {
        if(a.size()<b.size())
        {

            return -1;
        }
        else
        {
            for(int i=0;i<a.size();i++)
            {

                if(a[i]>b[i])
                    return 1;
                else
                {
                    if(a[i]<b[i])
                        return -1;
                }
            }
            return 0;
        }
    }
}
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

string esub(string a,string b)
{
reverse(a.begin(),a.end());
reverse(b.begin(),b.end());
a.shrink_to_fit();
b.shrink_to_fit();
    if(b.size()<a.size())
    {
        b.resize(a.size(),'0');

    }

    int bor=0;
    int dif;
    string result;
    result.resize(a.size());
    for(int i=0;i<a.size();i++)
    {
        dif=(num(a[i])-num(b[i])-bor);
        if(dif<0)
            bor=1;
        else
            bor=0;
        dif=(dif+10)%10;
        result[i]=chr(dif);

    }
    reverse(result.begin(),result.end());
    return result;
}
string sub(string a,string b)
{
    string minus="-";
    if(larger(a,b)>=0)
    {
        return trim(esub(a,b));
    }
    else
    {
       return minus.append(trim(esub(b,a)));
    }
}
int main()
{

string a,b;
int t;
cin>>t;
while(t--)
{
cin>>a>>b;
cout<<(sub(a,b));
cout<<endl;
}
return 0;
}
