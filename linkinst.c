#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" The data element of the linked list is  %d \n ", ptr->data);
        ptr = ptr->next;
    }
}

// Inserting a node in the starting
// struct Node* insert_start(struct Node* head,int data)
// {
//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr ->next = head;
//     ptr ->data = data;
//     return ptr;
// }
// Inserting a node at a given index

struct Node* insert_index(struct Node* head,int data,int index)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i;
    while(i!= index-1)
    {
        p = p->next;
        i++;
    }
    ptr ->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = second;

    second->data = 80;
    second->next = third;

    third->data = 90;
    third->next = NULL;

    traverse(head);
    // head = insert_start(head,50);
    // printf("List after the insertion of the new element in the start\n");
    printf("The list after insertion of an element at a given index\n");
    
    head = insert_index(head,56,1);

    traverse(head);

    return 0;
}