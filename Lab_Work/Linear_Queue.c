#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE
{
    int *array;
    int rear;
    int front;
    int size;
    int max_size;
} myQueue;

myQueue* init_Queue(int max_size);
void enQueue(myQueue* q, int x);
int deQueue(myQueue* q);
void show_queue(myQueue* q);

int main()
{
    myQueue* q;
    int choice = 0, x, max_size;
    scanf("%d", &max_size);
    q = init_Queue(max_size);
    while (1)
    {
        scanf("%d", &choice);
        if (choice == 0)
            q = init_Queue(max_size);
        else if (choice == 1)
        {
            scanf("%d", &x);
            enQueue(q, x);
        }
        else if (choice == 2)
        {
            x = deQueue(q);
            printf("%d\n", x);
        }
        else if (choice == 3)
        {
            printf("%d\n", q->size);
        }
        else if (choice == 4)
            show_queue(q);
        else
            break;
    }
    return 0;
}

myQueue* init_Queue(int max_size)
{
    myQueue* q;
    q = malloc(sizeof(myQueue));
    if (q == NULL)
        return NULL;
    q->array = malloc(sizeof(int) * max_size);
    if (q->array == NULL)
    {
        free(q);
        return NULL;
    }
    q->max_size = max_size;
    q->size = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

void enQueue(myQueue* q, int x)
{
    if (q->rear == q->max_size-1)
    {
        printf("OVERFLOW\n");
        return;
    }
    else
    {
        q->array[q->rear] = x;
        q->rear += 1;
        q->size += 1;
    }
}

int deQueue(myQueue* q)
{
    if (q->size == 0)
        return -9999;
    else
    {
        int temp = q->array[q->front];
        q->front += 1;
        q->size -= 1;
        return temp;
    }
}

void show_queue(myQueue* q)
{
    for (int i = q->front; i < q->rear-1; i++)
    {
        printf("%d, ", q->array[i]);
    }
    printf("%d\n", q->array[q->rear-1]);
}
