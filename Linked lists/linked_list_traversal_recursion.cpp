#include<iostream>

using namespace std;

struct node
{
    int val;
    struct node *next;
};
typedef struct node Node;

void traversal(Node*head)
{
    if(head==NULL)
    {
        cout<<"NULL";
        return;
    }
    else
    {
        cout<<head->val<<"->";
        traversal(head->next);
    }
}

int main()
{
    Node *n1,*n2;
    n1=new Node;
    n1->val=7;
    n2=new Node;
    n2->val=5;
    n1->next=n2;
    n2->next=NULL;
    traversal(n1);
    return 0;
}
