#include <stdio.h>

#define SIZE 6

struct CircularQueue
{
    int items[SIZE];
    int front, rear;
};

// Stack
struct Stack
{
    int items[SIZE];
    int top;
};

// Stack Functions
void initStack(struct Stack *s)
{
    s->top = -1;
}

int isStackEmpty(struct Stack *s)
{
    return (s->top == -1);
}

int isStackFull(struct Stack *s)
{
    return (s->top == SIZE - 1);
}

void push(struct Stack *s, int value)
{
    if (isStackFull(s))
    {
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(struct Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top--];
}

// Circular Queue Functions
void initQueue(struct CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(struct CircularQueue *q)
{
    return ((q->rear + 1) % SIZE == q->front);
}

int isQueueEmpty(struct CircularQueue *q)
{
    return (q->front == -1);
}

void enqueue(struct CircularQueue *q, int value)
{
    if (isQueueFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (isQueueEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
}

int dequeue(struct CircularQueue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % SIZE;
    }
    return value;
}

void reverseStackUsingQueue(struct Stack *s)
{
    struct CircularQueue q;
    initQueue(&q);

    while (!isStackEmpty(s))
    {
        enqueue(&q, pop(s));
    }

    while (!isQueueEmpty(&q))
    {
        push(s, dequeue(&q));
    }
}

void displayStack(struct Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

void displayQueue(struct CircularQueue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1)
    {
        printf("%d ", q->items[i]);
        if (i == q->rear)
        {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void handleQueue()
{
    struct CircularQueue q;
    initQueue(&q);

    while (1)
    {
        int option;
        printf("\nQueue Operations:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &option);

        if (option == 1)
        {
            int val;
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(&q, val);
        }
        else if (option == 2)
        {
            int val = dequeue(&q);
            if (val != -1)
            {
                printf("Dequeued: %d\n", val);
            }
        }
        else if (option == 3)
        {
            displayQueue(&q);
        }
        else if (option == 4)
        {
            break;
        }
        else
        {
            printf("Invalid input! Try again.\n");
        }
    }
}

void handleReverse()
{
    struct Stack s;
    initStack(&s);

    printf("\nEnter the number of elements in stack: ");
    int n;
    scanf("%d", &n);

    if (n > SIZE)
    {
        printf("Stack size exceeded!\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        push(&s, val);
    }

    printf("Original ");
    displayStack(&s);

    reverseStackUsingQueue(&s);

    printf("Reversed ");
    displayStack(&s);
}

int main()
{
    while (1)
    {
        int option;
        printf("\nSelect an operation:\n1. Queue Operations\n2. Reverse Stack Using Queue\n3. Exit\nEnter choice: ");
        scanf("%d", &option);

        if (option == 1)
        {
            handleQueue();
        }
        else if (option == 2)
        {
            handleReverse();
        }
        else if (option == 3)
        {
            printf("Exiting program.\n");
            return 0;
        }
        else
        {
            printf("Invalid input! Try again.\n");
        }
    }
}
