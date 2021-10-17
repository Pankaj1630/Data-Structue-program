#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

struct Node *atbeg(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Overflow\n");
    }
    else if (head == NULL)
    {
        ptr->data = data;
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
        return head;
    }
    else
    {
        ptr->data = data;
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        return head;
    }
    printf("Node is inserted in the list successfully!!");
}

struct Node *atend(struct Node *head, int data)
{
    struct Node *ptr, *p;
    p = head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (ptr == NULL)
    {
        printf("Overflow\n");
    }
    else if (head == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
        return head;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
        ptr->next = NULL;
        return head;
    }
    printf("Node is inserted sucessfully!");
}

struct Node *atpos(struct Node *head, int data, int pos)

{
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    p = head;
    if (ptr == NULL)
    {
        printf("Overflow\n");
    }

    else if (pos == 1)
    {

        head = atbeg(head, data);
        return head;
    }
    else
    {
        for (int i = 2; i < pos - 1; i++)
        {
            p = p->next;
        }
        ptr->prev = p;
        ptr->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = ptr;
        }
        p->next = ptr;
    }
    return head;
    printf("Node inserted successfully !");
}

struct Node *delbeg(struct Node *head)
{
    struct Node *ptr;
    if (head == NULL)
    {
        head = NULL;
        free(head);
        return head;
        printf("Node deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        return head;
        printf("Node is deleted\n");
    }
}

struct Node *delend(struct Node *head)
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("Overflow\n");
    }
    else if (head == NULL)
    {
        head = NULL;
        free(head);
        printf("Node is deleted\n");
        return head;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        return head;
        printf("Node is deleted");
    }
}
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty:\n");
    }
    else
    {

        struct Node *ptr;
        printf("printing values: ");
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int elem, pos, ch;
    while (1)
    {
        printf("Enter 1 to insert the element in the begining of the list:\n");
        printf("Enter 2 to insert the elemet in the end of the list:\n");
        printf("Enter 3 to insert the element at a specific position in the list:\n");
        printf("Enter 4 to delete the element at beginnig:\n");
        printf("Enter 5 to delete the element at the end:\n");
        printf("Enter 6 to delete the element at a specific position:\n");
        printf("Enter 7 to display the element:\n");
        printf("Enter 8 to exit the program:\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element you want insert in the list:\n");
            scanf("%d", &elem);
            head = atbeg(head, elem);
            break;
        case 2:
            printf("Enter the element you want inser in the list:\n");
            scanf("%d", &elem);
            head = atend(head, elem);
            break;
        case 3:
            printf("Enter the element you want to insert:\n");
            scanf("%d", &elem);
            printf("Enter the position you want to insert the element:\n");
            scanf("%d", &pos);
            head = atpos(head, elem, pos);
            break;
        case 4:
            head = delbeg(head);
            break;
        case 5:
            head = delend(head);
            break;
        case 8:
            display(head);
            break;
        case 9:
            printf("Your program is terminated");
            exit(0);
            break;
        default:
            printf("Invalid values");
            break;
        }
    }

    return 0;
}