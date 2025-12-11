#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert()
{
    int key, index;
    printf("Enter key to insert: ");
    scanf("%d", &key);
    index = key % SIZE;
    while (hashTable[index] != 0)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

void search()
{
    int key, index, found = 0;
    printf("Enter key to search: ");
    scanf("%d", &key);
    index = key % SIZE;
    for (int i = 0; i < SIZE; i++)
    {
        int check = (index + i) % SIZE;
        if (hashTable[check] == key)
        {
            printf("%d found at index %d\n", key, check);
            found = 1;
            break;
        }
    }
    if (!found)

        printf("%d not found in hash table\n", key);
}

void display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d] => %d\n", i, hashTable[i]);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}