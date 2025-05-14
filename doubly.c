#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (!newNode)
        return;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    Node *temp = head;
    while (temp)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void findEvenNumbers(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int found = 0;
    printf("Nodes with even numbers: ");
    Node *temp = head;
    while (temp)
    {
        if (temp->data % 2 == 0)
        {
            printf("%d ", temp->data);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("No even numbers found.");
    printf("\n");
}

void freeList(Node **head)
{
    Node *temp = *head;
    while (temp)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main()
{
    Node *head = NULL;
    int choice, value;

    do
    {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Find Even Numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertNode(&head, value);
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            findEvenNumbers(head);
            break;
        case 4:
            freeList(&head);
            printf("Exiting program. Memory freed.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}