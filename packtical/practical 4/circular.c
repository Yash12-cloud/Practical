#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char song[50];
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(char *song)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->next = NULL;
    return newNode;
}
void insertSong(char *song)
{
    struct Node *newNode = createNode(song);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Song '%s' added successfully.\n", song);
}
void deleteSong(char *song)
{
    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node *curr = head, *prev = NULL;
    do
    {
        if (strcmp(curr->song, song) == 0)
        {
            if (curr == head && curr->next == head)
            {
                free(curr);
                head = NULL;
            }
            else if (curr == head)
            {
                struct Node *temp = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = head->next;
                head = head->next;
                free(curr);
            }
            else
            {

                prev->next = curr->next;
                free(curr);
            }
            printf("Song '%s' deleted successfully.\n", song);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    printf("Song '%s' not found.\n", song);
}
void displayPlaylist()
{
    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Playlist: ");
    do
    {
        printf("%s ", temp->song);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int countSongs()
{
    if (head == NULL)
        return 0;
    int count = 0;
    struct Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
int main()
{
    int choice;
    char song[50];
    printf("=== Music Playlist System ===\n");
    while (1)
    {
printf("\n1. Add Song\n2. Delete Song\n3. Display Playlist\n4. Count Songs\n5. Exit\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
        case 1:
            printf("Enter song name: ");
            scanf("%s", song);
            insertSong(song);
            break;
        case 2:
            printf("Enter song to delete: ");

            scanf("%s", song);
            deleteSong(song);
            break;
        case 3:
            displayPlaylist();
            break;
        case 4:
            printf("Total Songs: %d\n", countSongs());
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
}
    }
    return 0;
}