#include <bits/stdc++.h>
#define lli long long int
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)


using namespace std;

vector<string> stringTovector(string s)
{
    int n = s.length();
    vector<string> stv;
    for(int i = 0; i<n;i++)
    {
        string temp="";
        if((s[i] >= '0' && s[i] <= '9')) 
        {
            int j = i;
            while(i!=s.size() && s[i] >= '0' && s[i] <= '9')
            {
                temp+=s[i];
                i++;
            }
            
            i--;
        }
        else 
        {
            temp+=s[i];
        }
        stv.push_back(temp);

    }

    return stv;
}
int prec(string c) 
{ 
    if(c == "^") 
    return 3; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "+" || c == "-") 
    return 1; 
    else
    return -1; 
} 
vector<string> infixToPostfix(vector<string> s) 
{ 
    stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns;
    for(int i = 0; i < l; i++) 
    { 
        if((s[i][0] >= '0' && s[i][0] <= '9')) 
            ns.push_back(s[i]);
        else if(s[i] == "(") 
           st.push("("); 
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c);
            } 
            if(st.top() == "(") 
            { 
                string c = st.top(); 
                st.pop(); 
            } 
        } 
        else{ 
            while(st.top() != "N" && prec(s[i]) <= prec(st.top())) 
            { 
                if(s[i]=="^"&&st.top()=="^") break;
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c); 
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(st.top() != "N") 
    { 
        string c = st.top(); 
        st.pop(); 
        ns.push_back(c); 
    } 
      
    return ns;
  
} 

struct node
{
  string s;
  node* lch=NULL,*rch=NULL;
};
lli evaluate(node *root)
{
   string s=root->s;
   lli ans=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^")
   return stoi(s);
   else
   {
     int lans=evaluate(root->lch),rans=evaluate(root->rch);
     if(s=="+")
       ans=lans+rans;
     else if(s=="-")
       ans=lans-rans;
     else if(s=="*")
       ans=lans*rans;
     else if(s=="/")
       ans=lans/rans;
     else
     {
       ans=1;
       f(i,0,rans)ans*=lans;
     }
   }
   return ans;
}
node* construct_tree(vt <string> postfix)
{
   node *root=NULL;
   vt <node*> stk;
   int i=0;
   while(i!=postfix.size())
   {
     if(postfix[i]!="+" && postfix[i]!="-" && postfix[i]!="*" && postfix[i]!="/" && postfix[i]!="^")
       {
         node *temp=(node *)malloc(sizeof(node));
         temp->s=postfix[i];
         f(j,0,postfix[i].size())
         if(postfix[i][j]<'0' || postfix[i][j]>'9')return NULL;
         stk.pb(temp);
       } 
     else
     {
       if(stk.size()<2)return NULL;
       node *s1=stk.back();
       stk.pop_back();
       node *s2=stk.back();
       stk.pop_back();
       node *temp=(node *)malloc(sizeof(node));
       temp->s=postfix[i];
       temp->lch=s2;
       temp->rch=s1;
       stk.pb(temp); 
     }
     i++;
   }
   if(stk.size()!=1)return NULL;
   return stk.back();
}



int main() 
{ 

  int t;cin>>t;


  while(t--)
  {


    int n;cin>>n;

    f(i,0,n)
    {
      string s;cin>>s;

      vt <string> postfix=stringTovector(s);

      postfix=infixToPostfix(postfix);

      node* root=construct_tree(postfix);

      if(root!=NULL)        
      cout<<evaluate(root)<<"\n";
      else cout<<"CANT BE EVALUATED\n";
    }


  }
  return 0; 	
}
