#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

void insert(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


ListNode* reverse(ListNode* &head)
{
    ListNode* prevptr=NULL;
    ListNode* currptr=head;
    ListNode* nextptr;

    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        
    }
return prevptr;
}

bool detectLoop(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *slow = head;
    ListNode *fast = head;

    ListNode *curr = head;

    while (slow != NULL and fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
            return true;
    }
    return false;
}

ListNode *findLoopNode(ListNode *head)
{
    if (head == NULL)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    while (slow != NULL and fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;

        if (slow == fast)
        {
            fast = head;
            while (fast != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow->next;
    }
    return NULL;
}

void removeLoop(ListNode* &head)
{
    if (head == NULL)
        return;

    ListNode *slow = head;
    ListNode *fast = head;

    while (slow!=NULL and fast!=NULL and fast->next!=NULL)
    {
        slow = slow->next;
        fast=fast->next;
        if (fast->next != NULL)
            fast = fast->next;

        if (slow == fast)
        {
            fast = head;
            while (fast->next != slow->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = NULL;
            return;
        }
    }
}

void display(ListNode *&head)
{
    if (head == NULL)
        return;

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << temp->val;
}

int main()
{
    ListNode *head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);

    display(head);
    ListNode *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = head->next->next;
    cout << endl;

    cout << detectLoop(head) << endl;

    ListNode *ans = findLoopNode(head);

    cout << "Cycle Starts with " << ans->val << endl;
    removeLoop(head);
    display(head);
    cout << endl;
    ListNode* ans1=reverse(head);
    display(ans1);
}