// This is the program of the insertion of the linked at every position

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

struct Node *empt(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *atbeg(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *atend(struct Node *head, int data)
{
    struct Node *p;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node *atpos(struct Node *head, int data, int pos)
{
    struct Node *p;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    p = head;
    if (pos == 1)
    {
        ptr->next = head;
        head = ptr;
        return head;
    }
    for (int i = 1; i < pos - 1 && p->next != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("There is no less than %d element ", pos);
    }
    else
    {
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}

struct Node *delbeg(struct Node *head)
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("The list is emply");
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}

struct Node *delend(struct Node *head)
{
    struct Node *ptr, *p;
    ptr = head;
    while (ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    if (ptr == head)
    {
        head = NULL;
        free(ptr);
    }
    else
    {
        p->next = NULL;
        free(ptr);
    }
    return head;
}


struct Node* delpos(struct Node* head,int pos)
{
    int i=1;
    struct Node* ptr,*p;
    ptr= head;
    while (i<pos-1)
    {
         ptr-ptr->next;
         i++;
    }
    p = ptr->next;
    ptr->next = p->next;
    free(p);
    
    return head;
}

void display(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("The list is empty\n\n");
    }
    else
    {
        printf("The element of the list is : ");
        while (ptr != NULL)
        {
            printf(" %d  ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int i, ch, data, pos;
    while (1)
    {
        printf("\nEnter 1 to insert element in a empty list:\n");
        printf("Enter 2 to insert element in at the beganing of list:\n");
        printf("Enter 3 to insert element in at the end of list:\n");
        printf("Enter 4 to insert element in at specific position list:\n");
        printf("Enter 5 to  delete the element at the beginning from the list:\n");
        printf("Enter 6 to delete from the end of the list:\n");
        printf("Enter 7 to delete from the specific position:\n");
        printf("Enter 8 to  display:\n");
        printf("Enter 9 to  Exit the program:\n");
        printf("Enter the choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (head != NULL)
            {
                printf("The list is not empty\n");
                break;
            }
            printf("Enter the data\n");
            scanf("%d", &data);
            head = empt(head, data);
            break;
        case 2:
            printf("Enter the data\n");
            scanf("%d", &data);
            head = atbeg(head, data);
            break;

        case 3:
            printf("Enter the data\n");
            scanf("%d", &data);
            head = atend(head, data);
            break;

        case 4:
            printf("Enter the data\n");
            scanf("%d", &data);
            printf("Enter the position\n");
            scanf("%d", &pos);
            head = atpos(head, data, pos);
            break;

        case 5:
            head = delbeg(head);
            break;
        case 6:
            head = delend(head);
            break;
        case 7:
            printf("Enter the position from you want to delete the element:\n");
            scanf("%d", &pos);
            head = delpos(head, pos);
            break;
        case 8:
            display(head);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}