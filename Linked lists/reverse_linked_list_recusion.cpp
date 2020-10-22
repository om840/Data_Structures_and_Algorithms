// Reversing a linked list using Recursion

#include<iostream>

using namespace std;

struct node
{
    int val;
    struct node *next;
}*start,*temp;

struct node* newnode()
{
    struct node *nw=new node;
    cout<<"\nEnter value for node:";
    cin>>nw->val;
    nw->next=NULL;
    return nw;
}

struct node* rev_link(struct node *n)
{
 if(n==NULL)
    return NULL;
 if(n->next==NULL)
 {
   start=n;
   return n;
 }

 struct node *p=rev_link(n->next);
 p->next=n;
 n->next=NULL;
 return n;
}

int main()
{
    int no,x;
    cout<<"Enter no of nodes :";
    cin>>no;
    for(int i=1;i<=no;i++)
    {
        if(i==1)
        {
          start=newnode();
          temp=start;
        }
        else
        {
           temp->next=newnode();
           temp=temp->next;
        }
    }
    cout<<"\nLinked list :";
    temp=start;
    while(temp!=NULL)
     {
         cout<<temp->val<<"->";
         temp=temp->next;
     }
     cout<<"NULL";
    rev_link(start);
    cout<<"\nReversed linked list :";
    temp=start;
    while(temp!=NULL)
     {
         cout<<temp->val<<"->";
         temp=temp->next;
     }
     cout<<"NULL";
    return 0;
}
