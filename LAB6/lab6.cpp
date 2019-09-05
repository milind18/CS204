#include<bits/stdc++.h>

using namespace std;


class avlnode
{

    public:
    int userid;
    int recharge;

    int lheight;
    int rheight;
    int balance;

    avlnode* left;
    avlnode* right;
    avlnode* parent;
    bool isleft;

    avlnode(int key,int rech,avlnode* par,bool lef)
    {

        userid=key;
        recharge=rech;


        lheight=0;
        rheight=0;
        balance=0;

        parent=par;
        isleft=lef;
        left=NULL;
        right=NULL;

    }

};

avlnode* root=NULL;
void printavlnode(avlnode* temp)
{
    if(temp->parent==NULL)
    {
        cout<<"NODE FOUND/CREATED: RECHARGE= "<<temp->recharge<<"   Parent= "<<"NULL"<<endl;
    }
    else
    {
        cout<<"NODE FOUND/CREATED: RECHARGE= "<<temp->recharge<<"   Parent= "<<temp->parent->userid<<endl;
    }


}
int unbalanced(avlnode* node)
{
    if(node->balance>=2||node->balance<=-2)
        return true;
}


void updateHeight(avlnode* x)
{
    int lheight=0;
    int rheight=0;

    if(x->left!=NULL)
    {
        lheight=max(x->left->lheight+1,lheight);
        lheight=max(x->left->rheight+1,lheight);
    }
    if(x->right!=NULL)
    {
        rheight=max(x->right->lheight+1,rheight);
        rheight=max(x->right->rheight+1,rheight);
    }
    x->lheight=lheight;
    x->rheight=rheight;
    x->balance=(x->rheight-x->lheight);
    return;
}
//MAKE PARENT-CHILD
void makepc(avlnode* parent,avlnode* child, bool left)
{
    if(parent==NULL)
    {
        child->parent=NULL;
        return;
    }


    if(left)
    {
        if(child==NULL)
        {
            parent->left=NULL;
            return;
        }
        parent->left=child;
        child->parent=parent;
        child->isleft=true;
    }
    else
    {
        if(child==NULL)
        {
            parent->right=NULL;
            return;
        }
        parent->right=child;
        child->parent=parent;
        child->isleft=false;
    }
    return;
}


avlnode* leftrotate(avlnode* x)
{

    avlnode* y=x->right;
    avlnode* t=y->left;

    makepc(x->parent,y,x->isleft);
    makepc(y,x,true);
    makepc(x,t,false);

    updateHeight(x);
    updateHeight(y);

    return y;
}
avlnode* rightrotate(avlnode* x)
{

    avlnode* y=x->left;
    avlnode* t=y->right;
    avlnode* temppar=x->parent;

    makepc(x->parent,y,x->isleft);
    makepc(y,x,false);
    makepc(x,t,true);

    updateHeight(x);
    updateHeight(y);

    return y;
    //change heights,return root

}
avlnode* rebalance(avlnode* node)
{
    avlnode* temp=node->parent;
    int height=1;
    bool left=node->isleft;

    while(temp!=NULL)
    {
       if(left==true)
       {


           updateHeight(temp);
           if(temp->balance<=-2)
           {


                assert(temp->left!=NULL);


                if(temp->left->balance<=-1)
                {
                    rightrotate(temp);
                }
                else
                {

                    leftrotate(temp->left);
                    rightrotate(temp);
                }
                temp=temp->parent;
                height--;
           }

       }
       else
       {

          updateHeight(temp);                //MAKE SURE THAT TEMP IS THE ROOT OF THE REBALANCED SUBTREE
           if(temp->balance>=2)
           {


            assert(temp->right!=NULL);

               if(temp->right->balance>=1)
               {
                   leftrotate(temp);
               }
               else
               {
                   rightrotate(temp->right);
                   leftrotate(temp);
               }
               temp=temp->parent;
               height--;
           }

       }
       left=temp->isleft;
       if(temp->parent==NULL)
            root=temp;
       temp=temp->parent;
       height++;
    }
}


avlnode* insert(avlnode* Node,int userid,int rech,avlnode* parent=NULL,bool left=true)
{
    if(Node==NULL)
    {
        avlnode* node=new avlnode(userid,rech,parent,left);
        if(parent!=NULL)
        {
            if(left)
            {

                parent->left=node;
            }
            else
            {

                parent->right=node;
            }
        }


        rebalance(node);
        return node;

    }


    if(Node->userid==userid)
    {
        Node->recharge+=rech;
        return Node;
    }

    if(Node->userid<userid)
    {

        return insert(Node->right,userid,rech,Node,false);

    }

    if(Node->userid>userid)
    {
        return insert(Node->left,userid,rech,Node,true);
    }



}



int main()
{

pair<int,int>maxans;
maxans.first=maxans.second=-1;
int n;
cin>>n;
int q;
cin>>q;

bool flag=false;;
while(q--)
{
    int op;
    int userid;
    int rech;
    cin>>op;
    if(op==1)
    {

        flag=true;
        cin>>userid;
        cin>>rech;
        avlnode* temp=insert(root,userid,rech);

        if(root==NULL)
            root=temp;



        if(temp->recharge>maxans.second)
        {

            maxans.first=userid;
            maxans.second=temp->recharge;
        }
    }
    if(op==2)
    {
        if(flag==false)
        {
            cout<<"No data available."<<endl;
            continue;
        }
        cout<<maxans.first<<endl;
    }

}
return 0;
}
