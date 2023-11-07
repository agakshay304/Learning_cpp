#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int value)
    {
        data=value;
        next=NULL;
    }
};
void InsertAtTail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next != NULL)
    {
        temp=temp ->next;
    }
    temp->next=n;
}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }cout<<endl;
}


    int length(node* head)
    {
        node* temp=head;
        int l=0;
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        return l;
    }

node* kappend(node* &head,int k)
{
    node* newhead;
    node* newtail;
    node* tail=head;
    int count=1;
    int l=length(head);
        k=k%l;
    while(tail->next!=NULL)
    {
       if(count==l-k)
       {
           newtail=tail;
       }
       if(count==l-k+1)
       {
           newhead=tail;
       }
       tail=tail->next;
       count++;
    }

    newtail->next=NULL;
    tail->next=head;


    return newhead;

}

    int main()
{
    node* head=NULL;
    InsertAtTail(head,1);
     InsertAtTail(head,2);
     InsertAtTail(head,3);
     InsertAtTail(head,4);
        InsertAtTail(head,5);
      InsertAtTail(head,6);
      node* newhead=kappend(head,4);
      display(newhead);
} 