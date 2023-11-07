#include <iostream>
using namespace std;

//Making a block of LinkedList
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

//Reversing kth node
node* reversek(node* &head,int k)
{
    //first we will reverse the linked list upto first k position.

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
        int count=0;
    while(currptr!=NULL && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;

        count++;
    }

    //Now we will give the work to recursion
    if(nextptr !=NULL)
    {
    head->next=reversek(nextptr,k);
    }

    return prevptr;

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
 int k=3;

 node* newhead=reversek(head,k);

 display(newhead);

}