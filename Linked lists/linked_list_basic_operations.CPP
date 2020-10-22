// Basic operations on Linked lists

#include<iostream>

using namespace std;

struct node
{int val;
 struct node *link;
}*temp,*start=NULL;

// Function to form new node
struct node* newnode()
{ struct node *nw=new node;
  cout<<"enter value for new node:";
  cin>>nw->val;
  nw->link=NULL;
  return nw;
}

// Function to insert a new node in the beginning

void insert_beg(struct node *nw)
{if(start==NULL)
 start=nw;
 else
  {nw->link=start;
   start=nw;
  }
}

// Function to insert a new node in the end

void insert_end(struct node *nw)
{temp=start;
 while(temp->link!=NULL)
  temp=temp->link;
  temp->link=nw;
}

// Function to insert a new node at nth position

void insert_pos(struct node *nw,int n)
{if(n==1)
 insert_beg(nw);
 else
 {temp=start;
  for(int i=1;i<n-1;i++)
  temp=temp->link;
  nw->link=temp->link;
  temp->link=nw;
 }
}

// Function to display all the nodes

void display()
{if(start==NULL)
 cout<<"\nlinked list is empty!!";
 else
 {struct node *p=start;
  cout<<"\nLinked list:";
  while(p!=NULL)
  {cout<<p->val<<"->";
   p=p->link;
  }
  cout<<"NULL\n";
 }
}

// Function to delete a node in the beginning

void delete_beg()
{if(start==NULL)
 cout<<"\nlinked list is empty!!";
 else
 start=start->link;
}

// Function to delete a node in the end

void delete_end()
{if(start==NULL)
 cout<<"\nlinked list is empty!!";
 else
 {temp=start;
  struct node *p;
  while(temp->link!=NULL)
   {p=temp;
    temp=temp->link;
   }
  p->link=NULL;
 }
}

// Function to delete a node at nth position

void delete_pos(int n)
{if(start==NULL)
  cout<<"\nlinked list is empty!!";
  else
 {if(n==1)
  delete_beg();
  else
  {temp=start;
   struct node *p;
    for(int i=1;i<n;i++)
    {p=temp;
     temp=temp->link;
    }
    p->link=temp->link;
  }
 }
}

int main()
{
 struct node *ne;
 int ch,x;
 do
 {cout<<"\n**** LINKED LIST ****";
  cout<<"\n1.insert at beg\n2.insert at end\n3.insert at a pos";
  cout<<"\n4.delete at beg\n5.delete at end\n6.delete at a pos";
  cout<<"\n7.Exit\nEnter a valid option:";
  cin>>ch;
  switch(ch)
  { case 1:ne=newnode();
	   insert_beg(ne);
	   display();
	   break;
    case 2:ne=newnode();
	   insert_end(ne);
	   display();
	   break;
    case 3:ne=newnode();
	   cout<<"enter value of pos:";
	   cin>>x;
	   insert_pos(ne,x);
	   display();
	   break;
    case 4:delete_beg();
	    display();
	    break;
    case 5:delete_end();
	    display();
	    break;
    case 6: cout<<"enter node pos to delete:";
	    cin>>x;
	    delete_pos(x);
	    display();
	    break;
  }
 }while(ch!=7);

 return 0;
}
