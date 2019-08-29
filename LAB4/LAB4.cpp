/*
Updated on Thursday,29th August 2019

Description: The data structure used to store all the variables is a trie. This data structure performs insertions and 
lookups of variables both in O(1) time! (more correctly O(k) time where k is the maximum possible length of the string 
which is given to be 15).Each node of the trie represents a string S and contains pointers to nodes whose strings have 
S as a prefix. 


*/




#include <bits/stdc++.h>


using namespace std;


int dbg=0;


int c(char a)
{
    if(a>='a'&&a<='z')
        return ((int)(a)-(int)('a'));
    else
    {
        if(a>='A'&&a<='Z')
        {

            return ((int)(a)-(int)('A')+26);
        }
    }
  
}

//   STACK CLASS for INFIX to POSTIFIX  CONVERSION
class strstack
{
public:
    vector<string> arr;
    void push(string x);
    string top();
    int pop();
    int isempty();

};


void strstack::push(string x)
{
    arr.push_back(x);
}
string strstack::top()
{
    return arr[arr.size()-1];
}
int strstack::pop()
{
    if(arr.size()==0)
    {
        return -1;
    }
    else
    {
        arr.pop_back();
        return 0;
    }
}
int strstack::isempty()
{
    if(arr.size()==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//Node structure for implementation of expression tree


struct node
{
    string x;
    bool op;
    node* left;
    node* right;

};

struct node* createnode(string inp,bool y=false,node*a=NULL,node*b=NULL)
{
    node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->x=inp;
    temp->op=y;
    temp->left=a;
    temp->right=b;
    return temp;
}

class nodestack
{
public:
    vector<node*> arr;
    void push(node* x);
    node* top();
    int pop();
    int isempty();

};


void nodestack::push(node* x)
{
    arr.push_back(x);
}

struct node* nodestack::top()
{
    return arr[arr.size()-1];
}
int nodestack::pop()
{
    if(arr.size()==0)
    {
        return -1;
    }
    else
    {
        arr.pop_back();
        return 0;
    }
}
int nodestack::isempty()
{
    if(arr.size()==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}









class tnode
{
public:
    tnode* let[52];//Pointer to the 52 nodes which are the 52 different  Latin letters
    bool assigned;
    string data;

    tnode()
    {
        assigned=false;
        for(int i=0;i<52;i++)
        {
            let[i]=NULL;
        }

    }

    tnode* createtnode(char a)
    {
        let[c(a)]=new tnode;
        return let[c(a)];
    }

    void delTnode()
    {
        for(int i=0;i<52;i++)
        {
            if(let[i]!=NULL)
            {
                let[i]->delTnode();
            }
        }
        delete this;
    }

};





class trie
{
public:

    tnode* root=NULL;
    trie()
    {
        root=new tnode;
    }
    void addString(string a,string val)
    {
        tnode* temp=root;
        for(int i=0;i<a.size();i++)
        {
            if(temp->let[c(a[i])]==NULL)
                temp=(temp->createtnode(a[i]));
            else
                temp=temp->let[c(a[i])];
        }
        temp->data=val;
	temp->assigned=true;
	
    }
    pair<bool,string> lookup(string a)
    {
        tnode*temp=root;
        for(int i=0;i<a.size();i++)
        {
            if(temp->let[c(a[i])]==NULL)
                return make_pair(false,"");
            temp=temp->let[c(a[i])];
        }
        if(temp->assigned==true)
            return make_pair(true,temp->data);
        else
            return make_pair(false,"");
    }
    void delTrie()
    {
       root->delTnode();	
    }


};


//Converts given string to its number

int num(string s)
{
    int ans=0;
    if(s[s.size()-1]=='-')
    {
        for(int i=0;i<s.size()-1;i++)
        {
            ans*=10;
            ans+=(s[i]-'0');
        }
        ans=-ans;
        return ans;
    }
    int siz=s.size()-1;
    for(int i=0;i<=siz;i++)
    {
        ans*=10;
        ans+=(s[i]-'0');

    }
    return ans;
}

//Converts a string to vector of characters
string str(vector<char>vec)
{
    string s;
    s.resize(vec.size());
    for(int i=0;i<vec.size();i++)
    {
        s[i]=vec[i];
    }
    return s;
}

//Converts an int to a string
string numtostr(int num)
{
    string x;
    int temp=num;
    bool flag=false;
    if(temp<0)
        {
            temp=-temp;
	    flag=true;
        }
    if(temp==0)
    {
        x.push_back('0');
    }
    while(temp!=0)
    {
        x.push_back((char)((temp%10)+(int)('0')));
            temp/=10;
    }
    string y;
    for(int i=x.size()-1;i>=0;i--)
    {
	
        y.push_back(x[i]);
    }
    if(flag==true)
    {
        y.push_back('-');
    }
    return y;
}

//Checks if an input character is an operation, opening parenthesis,closing parenthesis or a digit
int isalphabet(char a)
{
    int asc=(int)(a);
    if((asc>=(int)('a')&&asc<=(int)('z'))||(asc>=(int)('A')&&asc<=(int)('Z')))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isop(char a)
{
    if(a>='0'&&a<='9'||(isalphabet(a)))
        return 0;
    else
    {if(a=='(')
        return 2;
    else
    {
        if(a==')')
            return 3;
        else
            return 1;
    }

    }
}
int isnumeral(char a)
{
    int asc=(int)(a);
    if(asc>=(int)('0')&&asc<=(int)('9'))
        return 1;
    else
        return 0;
}


//Compares the precedence of operators a and 
int prec(char a)
{
    switch (a)
    {
        case '+':return 1;
                    break;
        case '-':return 1;
                    break;
        case '*':return 2;
                    break;
        case '/':return 2;
                    break;
        case '^':return 3;
                    break;
        case '@':return 4;
                    break;

    }
}
int compare(char a,char b)
{
    
    if(prec(a)>prec(b))
        return 1;
    else
    {
        if(prec(a)==prec(b))
            return 0;
        else
            return -1;
    }
}

//Converts the input into a vector of strings. Each string in the vector is either an operator or a number
vector<string> convert(string input,trie *var)
{
    vector<string> modified;
    char temp;
    for(int i=0;i<input.size();i++)
    {

        temp=input[i];
        if(isop(temp))
        {

            if((temp=='-')&&(i==0||(isop(input[i-1]))))
            {

                string x;
                x.resize(1);
                x[0]=0;
                modified.push_back("0");
                modified.push_back("@");
            }
            else
            {
                string s;
                s.resize(1);
                s[0]=temp;
                modified.push_back(s);
            }

        }
        else
        {

            if(isalphabet(temp))
            {
                string s;
                s.push_back(temp);
               
                while((i+1<input.size())&&isalphabet(input[i+1]))
                {
                    s.push_back(input[i+1]);
                    i=i+1;
                }

                pair<bool,string> xy=var->lookup(s);
                
		if(xy.first==true)
                {

                    modified.push_back(xy.second);
                
                }
                else
                {
                    string fail="fail";
                    modified.push_back(fail);
                    return modified;
                }
            }
            else
            {

                string s;
                s.push_back(temp);

                while((i+1<input.size())&&(isnumeral(input[i+1])))
                {
                    s.push_back(input[i+1]);
                    i=i+1;
                }
                modified.push_back(s);
            }
            
        }


    }
    return modified;
}
vector<string> infixtopost(vector<string> input)
{
    strstack stk;
    vector<string>modified;
    for(int i=0;i<input.size();i++)
    {

        int use=isop(input[i][0]);

        //If you find an operator decided whether to push it on the stack or to pop some elements of the stack
        if(use==1)
        {


            //IF you find an operator which has a lower priority than the top of the stack then push all the elements on to modified.
            while(!stk.isempty()&&isop(stk.top()[0])==1)
            {
              int val=compare(stk.top()[0],input[i][0]);
              //If top of the stack has a higher priority
              if(val==0&&input[i][0]=='^')
                {
                    break;
                }
              if(val>=0)
              {

                  modified.push_back(stk.top());
                  stk.pop();
              }
              else
              {
                  break;
              }

            }
            stk.push(input[i]);
        }
        else
        {//IF you find an opening parenthesis push it on to the stack.
            if(use==2)
            {
               stk.push((input[i]));
            }
            else
            {
                if(use==3)
                {
                    //IF you find a closing parenthesis pop all the elements until you find a closing parenthesis or the stack is empty.
                    while(stk.isempty()!=1&&isop(stk.top()[0])!=2)
                    {
                        modified.push_back(stk.top());
                        stk.pop();
                    }
                    //If there is an opening parenthesis on the stack remove it.
                    if(stk.isempty()!=1&&isop(stk.top()[0])==2)
                    {
                        stk.pop();
                    }
                }
                else
                {
                    modified.push_back(input[i]);
                }

            }
        }

    }
    while(!stk.isempty())
    {
        modified.push_back(stk.top());
        stk.pop();
    }
    return modified;

}

//Evaluation of the postfix using expression tress
struct node* makeTree(vector<string> input)
{
    nodestack stk;
    node * root=createnode(input[0]);
    stk.push(root);

    for(int i=1;i<input.size();i++)
    {

        if(isop(input[i][0]))
        {

            node*temp;

            node* r=stk.top();
            stk.pop();
            node* l=stk.top();
            stk.pop();
            temp=createnode(input[i],true,l,r);

            if(l==root||r==root)
            {
                root=temp;

            }
            stk.push(temp);
        }
        else
        {
            node* temp;
            temp=createnode(input[i]);
            stk.push(temp);
        }
    }
    return root;
}

int evaluate(struct node* root)
{
    if(root->op==true)
    {
        switch(root->x[0])
        {
            case '+': return evaluate(root->left)+evaluate(root->right);
                        break;
            case '-':  return evaluate(root->left)-evaluate(root->right);

                        break;
            case '*': return evaluate(root->left)*evaluate(root->right);
                        break;
            case '/': return evaluate(root->left)/evaluate(root->right);
                        break;
            case '^': return pow(evaluate(root->left),evaluate(root->right));
                        break;
            case '@': return evaluate(root->left)-evaluate(root->right);

        }
    }
    else
    {
        return num(root->x);
    }
}
void del(node* root)
{
    if(root->left!=NULL)
    {
        del(root->left);
    }

    if(root->right!=NULL)
    {
        del(root->right);
    }
    free(root);
}
int main()
{
	
int n;
cin>>n;
while(n--)
{

trie* var;
var=new trie;

int t;
cin>>t;
while(t--)
{
    

    string input;
    cin>>input;


    int eq=0;
    bool assign=false;


    for(;eq<input.size();eq++)
    {
        if(input[eq]=='=')
        {
            assign=true;
            break;
        }
    }


    if(assign==true)
    {

        string v;

        for(int i=0;i<eq;i++)
        {
            v.push_back(input[i]);
        }

        string modinput;

        for(int i=eq+1;i<input.size();i++)
        {
            modinput.push_back(input[i]);
        }

        vector<string> ans=convert(modinput,var);
        if(ans[ans.size()-1]=="fail")
        {
            cout<<"Cannot be evaluated"<<endl;
            break;
        }
        //Converting the infix expression to a postfix expression
        vector<string>ans2=infixtopost(ans);

        //Making the tree
        struct node* root=makeTree(ans2);
        //Evaluating the expression tree
        int finalans=evaluate(root);

        //If the variable is not in the map add it to the map
        var->addString(v,numtostr(finalans));

    }
    else
    {

    //Converting the given input to a vector of strings
    vector<string> ans=convert(input,var);
    if(ans[ans.size()-1]=="fail")
     {
        cout<<"Cannot be evaluated"<<endl;
        continue;
    }
    //Converting the infix expression to a postfix expression
    vector<string>ans2=infixtopost(ans);

    //Making the tree
    struct node* root=makeTree(ans2);
    //Evaluating the expression tree
    int finalans=evaluate(root);
    cout<<finalans<<endl;

    }



 }
 var->delTrie();

}       

return 0;
}
