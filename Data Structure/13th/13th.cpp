#include <stdio.h>
#include <malloc.h>
#include<iostream>
using namespace std;
struct edge;
struct node
{
	struct node *next;
	char name;
	struct edge *adj;
}*start=NULL;

struct edge
{
	char dest;
	struct edge *link;
};
struct node *find(char item);


void insert_node(char node_name)
{
	struct node *tmp,*ptr;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->name=node_name;
	tmp->next=NULL;
	tmp->adj=NULL;

	if(start==NULL)
	{
		start=tmp;
		return;
	}
	ptr=start;
	while( ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=tmp;
}

void delete_node(char u)
{
	struct node *tmp,*q;
	if(start->name == u)
	{
		tmp=start;
		start=start->next;
		free(tmp);
		return;
	}
	q=start;
	while(q->next->next != NULL)
	{
		if(q->next->name==u)
		{
			tmp=q->next;
			q->next=tmp->next;
			free(tmp);
			return;
		}
		q=q->next;
	}
	if(q->next->name==u)
	{
		tmp=q->next;
		free(tmp);
		q->next=NULL;
	}
}

void delnode_edge(char u)
{
	struct node *ptr;
	struct edge *q,*start_edge,*tmp;
	ptr=start;
	while(ptr!=NULL)
	{

		if(ptr->adj->dest == u)
		{
			tmp=ptr->adj;
			ptr->adj=ptr->adj->link;
			free(tmp);
			continue;
		}
		q=ptr->adj;
		while(q->link->link != NULL)
		{
			if(q->link->dest==u)
			{
				tmp=q->link;
				q->link=tmp->link;
				free(tmp);
				continue;
			}
			q=q->link;
		}
		if(q->link->dest==u)  		{
			tmp=q->link;
			free(tmp);
			q->link=NULL;
		}
		ptr=ptr->next;

	    }
	}

void insert_edge(char u,char v)
{
	struct node *locu,*locv;
	struct edge *ptr,*tmp;
	locu=find(u);
	locv=find(v);

	if(locu==NULL )
	{
		cout<<"Source node not present ,first insert node "<<u;
		return;
	}
	if(locv==NULL )
	{
		cout<<"Destination node not present ,first insert node:" <<v;
		return;
	}
	tmp=(struct edge *)malloc(sizeof(struct edge));
	tmp->dest=v;
	tmp->link=NULL;


	if(locu->adj==NULL)
	{
		 locu->adj=tmp;
		  return;
	}
	ptr=locu->adj;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	ptr->link=tmp;

}
struct node *find(char item)
{
	struct node *ptr,*loc;
	ptr=start;
	while(ptr!=NULL)
	{
		if(item==ptr->name)
		{
			loc=ptr;
			return loc;
		}
		else
			ptr=ptr->next;
	}
	loc=NULL;
	return loc;
}

void del_edge(char u,char v)
{
	struct node *locu,*locv;
	struct edge *ptr,*tmp,*q;
	locu=find(u);

	if(locu==NULL )
	{
		cout<<"Source node not present\n";
		return;
	}

	if(locu->adj->dest == v)
	{
		tmp=locu->adj;
		locu->adj=locu->adj->link;
		free(tmp);
		return;
	}
	q=locu->adj;
	while(q->link->link != NULL)
	{
		if(q->link->dest==v)
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}
	if(q->link->dest==v)
	{
		tmp=q->link;
		free(tmp);
		q->link=NULL;
		return;
	}
	cout<<"This edge not present in the graph\n";
}

void display()
{
	struct node *ptr;
	struct edge *q;

	ptr=start;
	while(ptr!=NULL)
	{
		printf("%c ->",ptr->name);
		q=ptr->adj;
		while(q!=NULL)
		{
			printf(" %c",q->dest);
			q=q->link;
		}
		printf("\n");
		ptr=ptr->next;
	 }
}
main()
{
	int choice;
	char node,origin,destin;
	while(1)
	{
		cout<<"1.Insert a node\n";
		cout<<"2.Insert an edge\n";
		cout<<"3.Delete a node\n";
		cout<<"4.Delete an edge\n";
		cout<<"5.Display\n";
		cout<<"6.Exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;

		switch(choice)
		{
		 case 1:
			cout<<"Enter a node to be inserted : ";
			fflush(stdin);
        cin>>node;
			insert_node(node);
			break;
		 case 2:
			cout<<"Enter an edge to be inserted : ";
			fflush(stdin);
			cin>>origin>>destin;
			insert_edge(origin,destin);
			break;
		 case 3:
			cout<<"Enter a node to be deleted : ");
			fflush(stdin);
			cin>>node;

			delete_node(node);

			delnode_edge(node);
			break;
		 case 4:
			cout<<"Enter an edge to be deleted : "\;
			fflush(stdin);
			cin>>origin>>destin;
			del_edge(origin,destin);
			break;
		 case 5:
			display();
			break;
		 case 6:
			break;
		 default:
    cout<<"Wrong choice\n";
			break;
		}}}
