#include <stdio.h>
#include <stdlib.h>

#define SIZE 11
#define MAX_LOOP 10

int hashTable1[SIZE];
int hashTable2[SIZE];

void initTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable1[i] = -1;
        hashTable2[i] = -1;
    }
}

int hash1(int key)
{
    return key % SIZE;
}

int hash2(int key)
{
    return (key / SIZE) % SIZE;
}

void displayTables()
{
    printf("\nHash Table 1:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d]: %d\n", i, hashTable1[i]);

    printf("\nHash Table 2:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d]: %d\n", i, hashTable2[i]);
}

int search(int key)
{
    int pos1 = hash1(key);
    int pos2 = hash2(key);

    if (hashTable1[pos1] == key)
        return 1;

    if (hashTable2[pos2] == key)
        return 2;

    return 0;
}

void insert(int key)
{
    int loopCount = 0;
    int currentKey = key;
    int table = 1;

    while (loopCount < MAX_LOOP)
    {
        if (table == 1)
        {
            int pos = hash1(currentKey);
            if (hashTable1[pos] == -1)
            {
                hashTable1[pos] = currentKey;
                return;
            }
            int displacedKey = hashTable1[pos];
            hashTable1[pos] = currentKey;
            currentKey = displacedKey;
            table = 2;
        }
        else
        {
            int pos = hash2(currentKey);
            if (hashTable2[pos] == -1)
            {
                hashTable2[pos] = currentKey;
                return;
            }
            int displacedKey = hashTable2[pos];
            hashTable2[pos] = currentKey;
            currentKey = displacedKey;
            table = 1;
        }
        loopCount++;
    }

    printf("Cycle detected! Rehash needed or resize tables!\n");
}

void delete(int key)
{
    int pos1 = hash1(key);
    int pos2 = hash2(key);

    if (hashTable1[pos1] == key)
    {
        hashTable1[pos1] = -1;
        printf("%d deleted from table 1\n", key);
        return;
    }

    if (hashTable2[pos2] == key)
    {
        hashTable2[pos2] = -1;
        printf("%d deleted from table 2\n", key);
        return;
    }

    printf("Key %d not found!\n", key);
}

int main()
{
    initTable();

    int choice, key;

    while (1)
    {
        printf("\nCuckoo Hashing Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            int found = search(key);
            if (found == 1)
                printf("Key %d found in table 1\n", key);
            else if (found == 2)
                printf("Key %d found in table 2\n", key);
            else
                printf("Key %d not found!\n", key);
            break;

        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            delete(key);
            break;

        case 4:
            displayTables();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
