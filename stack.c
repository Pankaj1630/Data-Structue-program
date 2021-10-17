// Stack implemention using array

// #include <stdio.h>
// #include <stdlib.h>
// int stack[100], n, top = -1, ch;

// void push()
// {
//     int val;

//     if (top == n)
//     {
//         printf("Overflow\n");
//     }
//     else
//     {
//         printf("Enter the value:\n");
//         scanf("%d", &val);
//         top++;
//         stack[top] = val;
//     }
// }

// void pop()
// {
//     if (top == -1)
//     {
//         printf("Underflow\n");
//     }
//     else
//     {
//         top--;
//     }
// }

// void display()
// {
//     printf("The values of the stack is : ");
//     for (int i = top; i >= 0; i--)
//     {
//         printf("%d ", stack[i]);
//     }
//     if (top == -1)
//     {
//         printf("The stack is empty\n");
//     }
//     printf("\n");
// }

// int main()
// {
//     printf("Enter the number you want to make the stack\n");
//     scanf("%d", &n);
//     while (1)
//     {
//         printf("Enter 1 to insert an element in the stack:\n");
//         printf("Enter 2 to delete an element from the stack:\n");
//         printf("Enter 3 to disaplay the stack:\n");
//         printf("Enter 4 to exit from the program:\n");
//         printf("Enter your choise:\n");
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
//             printf("You sucessfully terminated the progam");
//             exit(0);
//             break;
//         default:
//             printf("Invalid input\n");
//         }
//     }

//     return 0;
// }

// Stack implimention using linked list

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

struct Node *push(struct Node *top, int data)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (top == NULL)
    {
        temp->data = data;
        temp->next = NULL;
        top = temp;
        return top;
    }
    else
    {
        temp->data = data;
        temp->next = top;
        top = temp;
        printf("Node is inserted sucessfully\n");
        return top;
    }
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is underflow");
    }
    else
    {
        struct Node *temp = top;
        top = temp->next;
        free(temp);
        return top;
    }
}

struct Node *display(struct Node *top)
{
    struct Node *temp;
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{

    int ch, elem;
    while (1)
    {
        printf("Enter 1 to insert an element in the stack:\n");
        printf("Enter 2 to delete an element from the stack:\n");
        printf("Enter 3 to disaplay the stack:\n");
        printf("Enter 4 to exit from the program:\n");
        printf("Enter your choise:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element you want to insert in the stack:\n");
            scanf("%d", &elem);
            top = push(top, elem);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            printf("You sucessfully terminated the progam");
            exit(0);
            break;
        default:
            printf("Invalid input\n");
        }
    }

    return 0;
}