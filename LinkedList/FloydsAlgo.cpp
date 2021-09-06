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
void makecycle(node* &head,int pos)
{
    node* temp=head;
    node* startcycle;
    int count =1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startcycle=temp;
        }
        temp=temp->next;
         count++;
    }
    temp->next=startcycle;
}

bool checkcycle(node* head)
{
    node* fast=head;
    node* slow=head;


    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

void removecycle(node* &head)
{
    void removeLoop(node* head)
    {
       Node *slow = head, *fast = head; 
  
    while (fast!=NULL && fast->next!=NULL) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) {   // to detect the loop
            break; 
        } 
    } 
    if(slow!=fast)  // if loop doesn't exist
        return;
    if(slow==head) // starting point is head i.e tail connects to head as slow=head
    {
        while(fast->next!=head)
            fast=fast->next;
            fast->next=NULL;
            return;
    }
    else{
        slow=head;  // now move slow and fast 1 node at a time         
        while(slow->next!=fast->next){      // to find meeting point 
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL; 
        return;
    }
    }
    
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

      makecycle(head,3);
      cout<<checkcycle(head)<<endl;

      removecycle(head);
      display(head);
}