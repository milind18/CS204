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
	delete headt;
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
		head=head->next;
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
			delete headt;
			Len--;
			return;
		}
	}
}

void Search(float d)
{
	node* temp=head;
	while(temp!=NULL)
		{
        if(sqrt(temp->x*temp->x+temp->y*temp->y)<=d)
		{
			cout<<"("<<temp->x<<","<<temp->y<<") ";

		}
		temp=temp->next;
		}


}

bool Search(int a,int b)
{
	node* temp=head;
	while(temp!=NULL)
	{
		if(temp->x==a&&temp->y==b)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}

int length()
{
	return Len;
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
					cout<<Search(x,y)<<endl;
					break;
			case 6: cout<<length();
					break;

			default:cout<<"-1"<<endl;

		}

	}

	return 0;
}
