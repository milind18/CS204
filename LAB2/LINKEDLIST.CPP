#include<bits/stdc++.h>

using namespace std;
struct node
{
	int x;
	int y;
	node* next;
};

struct node* head=NULL;
int Len=0;

void AddFirst(int a,int b)
{
	node* n;
	n=(struct node*)malloc(sizeof(struct node));
	n->x=a;
	n->y=b;
	n->next=head;
	head=n;
	Len++;

}

void DelFirst()
{
	if(Len==0)
		{
		    cout<<-1<<endl;
		    return;
		}
	struct node* headt=head;
	head=head->next;
	free(headt);
	Len--;
	return;
}
void Del(int a,int b)
{
	if(Len==0)
	{
		cout<<-1<<endl;
		return;
	}

	if(head->x==a&&head->y==b)
	{
	    node*temp=head;
		head=head->next;
		free(head);
	    temp=NULL;
		Len--;
		return;
	}

	node* temp=head;
	while(temp->next!=NULL)
	{
		struct node* headt;
		if(temp->next->x==a&&temp->next->y==b)
		{
			headt=temp->next;
			temp->next=temp->next->next;
			free(headt);
			Len--;
			return;
		}
		temp=temp->next;

	}
	cout<<-1<<endl;
	return;
}

void Search(float d)
{
	node* temp=head;
	int f=0;
	int c=0;
	while(temp!=NULL)
		{
        if(sqrt(temp->x*temp->x+temp->y*temp->y)<=d)
		{
			c++;
		f=1;

		}
		temp=temp->next;
		}
	if(f==0)
		cout<<-1;
    else
        cout<<c;

	cout<<endl;



}

void Search(int a,int b)
{
	node* temp=head;
	while(temp!=NULL)
	{
		if(temp->x==a&&temp->y==b)
		{
			cout<<"True"<<endl;
			return;
		}
		temp=temp->next;
	}
	cout<<"False"<<endl;
	return ;
}

int length()
{
	cout<<Len<<endl;
}
int main()
{
	int t;
	cin>>t;

	int f,x,y;
	float d;
	while(t--)
	{
		cin>>f;
		switch(f)
		{

			case 1: cin>>x>>y;
					AddFirst(x,y);
					break;
			case 2: DelFirst();
					break;
			case 3:	cin>>x>>y;
					Del(x,y);
					break;
			case 4:	cin>>d;
					Search(d);
					break;
			case 5: cin>>x>>y;
					Search(x,y);

					break;
			case 6: length();
					break;

			default:cout<<"-1"<<endl;

		}

	}

	return 0;
}
