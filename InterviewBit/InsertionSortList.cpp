#include <iostream>
using namespace std;

//Making a block of LinkedList
class ListNode
{
    public:
    int val;
    ListNode* next;

    ListNode(int value)
    {
        val=value;
        next=NULL;
    }
};
void InsertAtTail(ListNode* &head,int val)
{
    ListNode* n=new ListNode(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    ListNode* temp=head;
    while(temp->next != NULL)
    {
        temp=temp ->next;
    }
    temp->next=n;
}


ListNode* insertionSortList(ListNode* A) {
    ListNode* dummy=new ListNode(10000);
    while(A)
    {
        ListNode* next=A->next;
        ListNode* temp=dummy;

        while(temp->next && temp->next->val<A->val)
        {
            temp=temp->next;
        }
        A->next=temp->next;
        temp->next=A;
        A=next;
    }
    return dummy->next;
}
void display(ListNode* head)
{
    ListNode* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
}
int main()
{
    ListNode* head=NULL;
    InsertAtTail(head,3);
     InsertAtTail(head,2);
 InsertAtTail(head,5);
 InsertAtTail(head,1);
 InsertAtTail(head,8);

    insertionSortList(head);
    display(head);
}