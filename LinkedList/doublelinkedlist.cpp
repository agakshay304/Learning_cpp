#include <iostream>
using namespace std;

//Making a block of double LinkedList
class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int value)
    {
        data=value;
        next=NULL;
        prev=NULL;
    }
};

void insertathead(node* &head,int value)
{
    node* n=new node(value);
    n->next=head;

    if(head!=NULL)
    {
        head->prev=n;
    }
    head=n;
}


void insertattail(node* &head,int value)
{
    node* n=new node(value);
    if(head==NULL)
    {
            insertathead(head,value);
            return;
    }
node* temp=head;
while(temp->next!=NULL)
{
    temp=temp->next;
}
temp->next=n;
n->prev=temp;
}

void display(node* head)
{
    node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
void deleteathead(node* &head)
{
    node* todelete=head;

    head=head->next;
    head->prev=NULL;

    delete todelete;
}
void deletion(node* &head,int pos)
{
    node* temp=head;
    int count=1;


    if(temp==NULL)
    {
        cout<<"Linked List is Empty";
        return;
    }

    if(pos==1)
    {
        deleteathead(head);
    }

    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;

        delete temp;
}


int main()
{
    node* head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertathead(head,4);
    display(head);
    cout<<endl;
    deletion(head,3);
    display(head);

}