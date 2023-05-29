#include <stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct
{
    int top;
    int arr[Max];
} Stack;

void init(Stack* stack)
{
    stack->top = -1;
}

int is_empty(Stack* stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

int is_full(Stack* stack)
{
    if (stack->top == Max - 1)
        return 1;
    else
        return 0;
}

int peek(Stack* stack)
{
    if (stack->top==-1)
        return -1000000;
    else
        return stack->top;
}

int pop(Stack* stack)
{
    if (is_empty(stack))
    {
        printf("Stack Underflow\n");
        return -1000000;
    }
    else
    {
        int x = stack->arr[stack->top];
        stack->top -= 1;
        return x;
    }
}

void push(Stack* stack, int x)
{
    if (is_full(stack))
        printf("Stack Overflow\n");
    else
    {
        stack->top += 1;
        stack->arr[stack->top] = x;
    }
}

void show_stack(Stack* stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    init(stack);
    push(stack, 10);
    push(stack, 40);
    push(stack, 90);
    pop(stack);
    show_stack(stack);
    free(stack);
    return 0;
}
