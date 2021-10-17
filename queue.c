// #include <stdio.h>
// #include <stdlib.h>
// int q[100], front = -1, rear = -1, n;

// void push()
// {
//     int data;
//     if (rear == n - 1)
//     {
//         printf("Overflow\n");
//     }
//     else
//     {
//         if (front = -1)
//         {
//             front = 0;
//         }
//         printf("Enter the element:\n");
//         scanf("%d", &data);
//         rear++;
//         q[rear] = data;
//     }
// }

// void pop()
// {
//     if (front == -1 || front > rear)
//     {
//         printf("underflow\n");
//     }
//     else
//     {
//         // printf("%d", q[front]);
//         front++;
//     }
// }

// void display()
// {
//     int i;
//     if (front == -1)
//     {
//         printf("The queue is empty:\n");
//     }
//     else
//     {
//         printf("Elements: ");
//         for (i = front; i <= rear; i++)
//         {
//             printf("%d ", q[i]);
//         }
//     }
//     printf("\n");
// }

// int main()
// {
//     int ch;
//     printf("Enter the number of element you want to insert:\n");
//     scanf("%d", &n);
//     while (1)
//     {
//         printf("Enter 1 to inset an element into the queue:\n");
//         printf("Enter 2 to delete an element into the queue:\n");
//         printf("Enter 3 to display an element into the queue:\n");
//         printf("Enter 4 to exit an element into the queue:\n");
//         printf("Enter your choice:\n");
//         scanf("%d", &ch);
//         switch (ch)
//         {
//         case 1:
//             push();
//             break;
//         case 2:
//             pop();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             printf("Program terminated successfully !");
//             exit(0);
//             break;
//         default:
//             printf("Invalid input:\n");
//             break;
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *rear = NULL;
struct Node *front = NULL;

void push()
{
    int item;
    printf("Enter the element you want to insert in the list:\n");
    scanf("%d",&item);
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("Overflow\n");
    }
    else{
        ptr->data=item;
        if(rear == NULL)
        {
            rear = ptr;
            front = ptr;
            rear->next = NULL;
            front->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear ->next = NULL;
        }
    }
}

void pop()
{
    struct Node*ptr;
    if(front==NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        
        front=front->next;
        free(ptr);
    }
}

void display()
{
    struct Node*ptr;
    ptr = front;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Printing the value..\n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter 1 for insertion of the element:\n");
        printf("Enter 2 for the deletion of the element:\n");
        printf("Enter 3 for the display the queue:\n");
        printf("Enter 4 for the exit from the program:\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("You successfuly exit from the program");
            exit(0);
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }
    return 0;
}