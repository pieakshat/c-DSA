#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20
#define TABLE_SIZE 11
#define EMPTY -1

// ------------------ Graph Section -------------------

int graph[MAX][MAX];
int visited[MAX];
int n; // Number of vertices

void inputGraph()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
}

void DFSUtil(int v)
{
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
            DFSUtil(i);
    }
}

void DFS(int start)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS Traversal: ");
    DFSUtil(start);
    printf("\n");
}

void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// ------------------ Hashing Section -------------------

int hashTable[TABLE_SIZE];

void initHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}

int linearProbing(int key, int step)
{
    int index = key % TABLE_SIZE;
    int start = index;

    while (hashTable[index] != EMPTY)
    {
        index = (index + step) % TABLE_SIZE;
        if (index == start)
            return -1; // Full table
    }
    return index;
}

void insertHash(int key, int step)
{
    int index = linearProbing(key, step);
    if (index == -1)
        printf("Hash Table is full. Couldn't insert key %d\n", key);
    else
    {
        hashTable[index] = key;
        printf("Inserted key %d at index %d\n", key, index);
    }
}

void displayHashTable()
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == EMPTY)
            printf("[%d]: ---\n", i);
        else
            printf("[%d]: %d\n", i, hashTable[i]);
    }
}

// ------------------ Menu -------------------

int main()
{
    int choice, key, step, start;

    initHashTable();

    while (1)
    {
        printf("\n==== Main Menu ====\n");
        printf("1. Input Graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Insert into Hash Table (Linear Probing)\n");
        printf("5. Display Hash Table\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputGraph();
            break;
        case 2:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &start);
            if (start >= 0 && start < n)
                BFS(start);
            else
                printf("Invalid vertex.\n");
            break;
        case 3:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &start);
            if (start >= 0 && start < n)
                DFS(start);
            else
                printf("Invalid vertex.\n");
            break;
        case 4:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            printf("Enter slot step (2 / 3 / 4): ");
            scanf("%d", &step);
            if (step == 2 || step == 3 || step == 4)
                insertHash(key, step);
            else
                printf("Invalid step size. Use 2, 3 or 4.\n");
            break;
        case 5:
            displayHashTable();
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}