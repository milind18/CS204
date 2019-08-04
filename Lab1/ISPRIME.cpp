#include<bits/stdc++.h>

using namespace std;
//Checks if a is prime

//Given a positive integer with leading zeroes it removes the leading zeroes.
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
    reverse(result.begin(),result.end());
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
//Returns  a digit of the result
pair<char,string> resdigit(string check, string b)
{
    int i=0;
    string x=trim(check);
    while(larger(x,b)>=0)
    {

        x=esub(x,b);
        i++;
    }
    return make_pair(chr(i),trim(x));
}
// Returns the <quotient,remainder> pair when x is divided by y
pair<string,string> divide(string x,string y)
{
    string a=trim(x);
    string b=trim(y);
    if(larger(a,b)==0)
    {
        return make_pair("1","0");
    }
    else
    {
        if(larger(a,b)==-1)
        {
            return make_pair("0",a);
        }
    }

        string result;
        string check;

        pair<char,string> info;

        check.resize(b.size()+1);
        result.resize(a.size()+1);

        for(int i=0;i<check.size();i++)
        {
            check[i]='0';
        }

      for(int i=0;i<=a.size();i++)
      {

         info=resdigit(check,b);

         result[i]=info.first;
         for(int j=0;j<b.size()-info.second.size();j++)
         {
             check[j]='0';
         }
         int k=0;
         for(int j=b.size()-info.second.size();k<info.second.size();j++)
         {
             check[j]=info.second[k++];
         }
        if(i!=a.size())
           check[b.size()]=a[i];
        else
        {
            check.resize(b.size());
            break;
        }

        }

    return make_pair(trim(result),trim(check));

}
bool isprime(string x)
{
   string a=trim(x);
    if(larger("9",a)>=0)
    {
       switch(num(x[0]))
        {
            case 1:return false;
            case 4:return false;
            case 6:return false;
            case 8:return false;
            case 9:return false;
            case 2:return true;
            case 3:return true;
            case 5:return true;
            case 7:return true;

        }

    }

    int limsize=ceil(a.size()*0.5)+1; // Upper bound in the number of digits in square root.

    string limit;
    limit.resize(limsize);
    limit[0]='1';

    for(int i=1;i<limsize;i++)  // Upper bound on square root.
    {
        limit[i]='0';
    }
  //  cout<<limit<<endl;


    string num="2";

    while(larger(limit,num)==1)
        {

            if(divide(a,num).second=="0")
               {
                   return false;
               }
            num=sum(num,"1");

        }
        return true;
}



int main()
{


/*if(isprime(a))
    cout<<"YES";
else
    cout<<"NO";
*/
string a;
int q=10;
cin>>q;
while(q--)
{
    cin>>a;
    if(isprime(a))
    {
        cout<<"Prime"<<endl;
    }
    else
    {
        cout<<"Not a Prime"<<endl;
    }
}
return 0;

}
