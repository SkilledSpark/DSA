#include <stdio.h>
#include <stdlib.h>

#define N 5

// Defining global variables
int arr[N];
int top = -1;
int value;
int max = N;

void push(int input);
int pop();
void total(int arr[]);

int main()
{
    int input, a;
    
    while (1)
    {
        // Input Prompt
        printf("1-Push\n");
        printf("2-Pop\n");
        printf("3-Print top number\n");
        printf("4-Print all elements\n");
        printf("5-Quit\n\n");
        printf("Input: ");
        scanf("%d", &input);

        // Checking for input
        if (input == 1)
        {
            printf("Enter a value to push: ");
            scanf("%d", &a);
            push(a);
        }
        else if (input == 2)
        {
            pop();
        }
        else if (input == 3)
        {
            if (top != -1)
            {
                a = arr[top];
                printf("%d\n", a);
            }
            else
                printf("Stack Underflow\n");
        }
        else if (input == 4)
            total(arr);
        else if (input == 5)
            break;
        else
            printf("Invalid input\n");
        
        system("pause");
        system("cls");
    }
    
    return 0;
}

void push(int input)
{
    if (top != max - 1)
    {
        top += 1;
        arr[top] = input;
    }
    else
        printf("Stack Overflow\n");
}

int pop()
{
    if (top != -1)
    {
        value = arr[top];
        top -=1;
        printf("%d was popped\n", value);
        return value;
    }
    else
        printf("Stack Underflow\n");
    return -1;
}

void total(int arr[])
{
    int i, a = 0;
    for (i = top; i >= 0; i--)
    {
        a = arr[i];
        printf("%d ", a);
    }
    printf("\n");
}