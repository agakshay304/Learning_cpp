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

node* recursivereverse(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //we will only reverse the head position of linkedlist & rest will be done by recursion
    node* newhead=recursivereverse(head->next);

    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* iteratorreverse(node* &head)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        
    }
return prevptr;

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


int main()
{
    node* head=NULL;
    InsertAtTail(head,1);
     InsertAtTail(head,2);
 InsertAtTail(head,3);
 display(head);

 //node* newhead=recursivereverse(head);
 //display(newhead);

 node *newhead1=iteratorreverse(head);
 display(newhead1);

}