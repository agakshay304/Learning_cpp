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

void InsertAtHead(node* &head,int val)
{
       node* n=new node(val); 
        n->next=head;
        head=n;

}

//For Deleting Element from Head
void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;

    delete todelete;
}

//For Deleting Element From a Specific Position
void deleteAt(node* &head,int val)
{
    //if linkedlist is empty
    if(head==NULL)
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }

    //if LinkedList Has Only One Element
    if(head->next==NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node *todelete=temp->next;
    temp->next=temp->next->next;

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

bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main()

{
    node* head=NULL;
    InsertAtTail(head,1);
     InsertAtTail(head,2);
 InsertAtTail(head,3);

 InsertAtHead(head,10);
 display(head);

 cout<<search(head,3);

 deleteAt(head,2);
 display(head);
}