#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define ACTION_LEN 200

char undoStack[MAX][ACTION_LEN];
int undoTop = -1;
char redoStack[MAX][ACTION_LEN];
int redoTop = -1;

void push(char s[][ACTION_LEN], int *top, const char *str)
{
    if (*top >= MAX - 1)
    {
        printf("Stack full (max %d)\n", MAX);
        return;
    }
    strcpy(s[++(*top)], str);
}

char *pop(char s[][ACTION_LEN], int *top)
{
    if (*top == -1)
        return NULL;
    return s[(*top)--];
}

void performAction(const char *action)
{
    push(undoStack, &undoTop, action);
    // clear redo stack when new action is performed
    redoTop = -1;
    printf("Action performed: %s\n", action);
}

void doUndo()
{
    char *a = pop(undoStack, &undoTop);
    if (a == NULL)
    {
        printf("Nothing to undo!\n");
        return;
    }
    push(redoStack, &redoTop, a);
    printf("Undo: %s\n", a);
}

void doRedo()
{
    char *a = pop(redoStack, &redoTop);
    if (a == NULL)
    {
        printf("Nothing to redo!\n");
        return;
    }
    push(undoStack, &undoTop, a);
    printf("Redo: %s\n", a);
}

void printStacks()
{
    printf("\n--- Undo Stack (top -> bottom) ---\n");
    if (undoTop == -1) printf("[empty]\n");
    else {
        for (int i = undoTop; i >= 0; --i)
            printf("%d: %s\n", i, undoStack[i]);
    }

    printf("\n--- Redo Stack (top -> bottom) ---\n");
    if (redoTop == -1) printf("[empty]\n");
    else {
        for (int i = redoTop; i >= 0; --i)
            printf("%d: %s\n", i, redoStack[i]);
    }
    printf("\n");
}

/* Helper to read a full line of input into buf (removes trailing newline) */
void readLine(char *buf, int size)
{
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') buf[len-1] = '\0';
}

int main()
{
    int choice = 0;
    char input[ACTION_LEN];

    while (1)
    {
        printf("========== TEXT EDITOR UNDO/REDO MENU ==========\n");
        printf("1. Perform Action (type an action)\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Show undo/redo stacks\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            // invalid input, clear stdin and continue
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid choice. Try again.\n\n");
            continue;
        }
        // consume leftover newline before using fgets/readLine
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (choice)
        {
            case 1:
                printf("Enter action (max %d chars): ", ACTION_LEN - 1);
                readLine(input, ACTION_LEN);
                if (strlen(input) == 0) {
                    printf("Empty action ignored.\n");
                } else {
                    performAction(input);
                }
                break;

            case 2:
                doUndo();
                break;

            case 3:
                doRedo();
                break;

            case 4:
                printStacks();
                break;

            case 5:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid option. Choose 1-5.\n");
        }

        printf("\n");
    }

    return 0;
}
