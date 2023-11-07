#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
 
void deleteNodeWithoutHead(struct Node* pos)
{
    if (pos == NULL) // If linked list is empty
        return;
    else {
 
        if (pos->next == NULL) {
            printf("This is last node, require head, can't "
                   "be freed\n");
            return;
        }
 
        struct Node* temp = pos->next;
 
        pos->data = pos->next->data;
 
        pos->next = pos->next->next;
 
        free(temp);
    }
}
 
void print(struct Node* head)
{
    struct Node* temp = head;
    while (temp) {
        printf(" %d\t", temp->data);
        temp = temp->next;
    }
 
   printf("NULL");
}
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
int main()
{
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    printf("Initial Linked List: \n");
    print(head);
 
    struct Node* del = head->next;
    deleteNodeWithoutHead(del);
 
    printf("\nFinal Linked List after deletion of 15:\n");
    print(head);
 
    return 0;
}