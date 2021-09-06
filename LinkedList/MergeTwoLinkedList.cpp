#include <iostream>
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


node* merge(node* &head1,node* &head2)
{
    node* p1=head1;
    node* p2=head2;

    node* dummynode=new node(-1);
    node* p3=dummynode;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL)
    {
        p3->next=p1;
            p1=p1->next;
            p3=p3->next;
    }

    while(p2!=NULL)
    {
         p3->next=p2;
            p2=p2->next;
            p3=p3->next;
    }
    return dummynode->next;
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



node* recursivemerge(node* &head1,node* &head2)
{
    if(head1==NULL)
    {
        return  head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* result;

    if(head1->data<head2->data)
    {
        result=head1;
        result->next=recursivemerge(head1->next,head2);

    }
    else{
        result=head2;
        result->next=recursivemerge(head1,head2->next);
    }
return result;
}

int main()
{
    int a[]={1,3,5,7};
    int b[]={2,4,6};
    node* head1=NULL;
    for(int i=0;i<4;i++)
    {
        InsertAtTail(head1,a[i]);
    }
    display(head1);
    cout<<endl;
    node* head2=NULL;
    for(int i=0;i<3;i++)
    {
        InsertAtTail(head2,b[i]);
    }

    display(head2);
    cout<<endl;
    node* result=recursivemerge(head1,head2);
    display(result);
    
}
