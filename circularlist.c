#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

struct Node *emptylist(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)

    {
        ptr->data = data;
        head = ptr;
        ptr->next = head;
        return head;
    }
}

struct Node *insert_begin(struct Node *head, int data)
{
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    if (ptr == NULL)
    {
        printf("Overflow\n");
    }
    else if (head == NULL)
    {
        head = emptylist(head, data);
        return head;
    }
    else
    {
        ptr->data = data;
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        ptr->next = head;
        p->next = ptr;
        head = ptr;
        return head;
    }
    printf("Node is inserted successfully ");
}

struct Node *insert_end(struct Node *head, int data)
{
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Overflow\n");
    }
    if (head == NULL)
    {
        head = emptylist(head, data);
        return head;
    }
    else
    {
        ptr->data = data;
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr->next;
        p->next = ptr;
        ptr->next = head;
        return head;
    }
}

struct Node *insert_pos(struct Node *head, int data, int pos)
{
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    p = head;
    if (pos == 1)
    {
        head = insert_begin(head, data);
        return head;
    }
    else
    {
        for (int i = 2; i < pos - 1; i++)
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
        return head;
    }
    printf("Node is iserted sucessfully\n");
}

struct Node *delbeg(struct Node *head)
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        return head;
        printf("Head is deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        return head;
    }
}

struct Node *delend(struct Node *head)
{
    struct Node *ptr, *p;
    ptr = head;
    if (ptr->next == head)
    {
        head == NULL;
        free(head);
        return head;
    }
    while (ptr->next != head)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct Node *delpos(struct Node *head, int pos)
{
    int i = 1;
    struct Node *ptr, *p;
    ptr = head;
    while (i < pos - 1)
    {
        ptr - ptr->next;
        i++;
    }
    p = ptr->next;
    ptr->next = p->next;
    free(p);

    return head;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct Node *ptr;
        ptr = head;
        printf("The element of the list is : ");
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
    printf("\n");
}

int main()
{
    int elem, pos, ch, i;
    while (1)
    {
        printf("Enter 1 to insert element in a empty list:\n ");
        printf("Enter 2 to insert element at the beginnin of the list:\n ");
        printf("Enter 3 to insert the element at the end of the list:\n ");
        printf("Enter 4 to insert the element at a specific location in the list:\n ");
        printf("Enter 5 to delete the element at the beginning:\n");
        printf("Enter 6 to delete the element at the end:\n");
        printf("Enter 7 to delete the element at the specific position:\n");
        printf("Enter 8 to display the list:\n ");
        printf("Enter 9 to exit the program\n");
        printf("Enter the choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element you want to insert: ");
            scanf("%d", &elem);
            head = emptylist(head, elem);
            break;
        case 2:
            printf("Enter the element you want to insert: ");
            scanf("%d", &elem);
            head = insert_begin(head, elem);
            break;
        case 3:
            printf("Enter the element you want to insert: ");
            scanf("%d", &elem);
            head = insert_end(head, elem);
            break;

        case 4:
            printf("Enter the element you want to insert: ");
            scanf("%d", &elem);
            printf("Enter the position at you want to insert the new node: ");
            scanf("%d", &pos);
            head = insert_pos(head, elem, pos);
            break;

        case 5:
            head = delbeg(head);
            break;
        case 6:
            head = delend(head);
            break;
        case 7:
            printf("Enter the position you want to delete the element: ");
            scanf("%d", &pos);
            head = delpos(head, pos);
            break;
        case 8:
            display(head);
            break;
        case 9:
            printf("You successfully terminated the program");
            exit(0);
            break;

        default:
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
}