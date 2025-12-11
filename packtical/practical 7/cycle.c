#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

// ---------------- TRIE NODE ----------------
typedef struct TrieNode {
    struct TrieNode *child[52];
    int isEnd;
} TrieNode;

// convert char to index
int getIndex(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return 26 + (c - 'A');
    return -1;
}

TrieNode* createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = 0;
    for (int i = 0; i < 52; i++) node->child[i] = NULL;
    return node;
}

void insert(TrieNode *root, char *key) {
    TrieNode *temp = root;
    for (int i = 0; key[i]; i++) {
        int idx = getIndex(key[i]);
        if (idx < 0) continue;
        if (!temp->child[idx])
            temp->child[idx] = createNode();
        temp = temp->child[idx];
    }
    temp->isEnd = 1;
}

int search(TrieNode *root, char *key) {
    TrieNode *temp = root;
    for (int i = 0; key[i]; i++) {
        int idx = getIndex(key[i]);
        if (idx < 0) continue;
        if (!temp->child[idx]) return 0;
        temp = temp->child[idx];
    }
    return temp->isEnd;
}

// -------------- PART 1: Read keys from file ----------------
void part1(TrieNode *root) {
    FILE *fp = fopen("keys.txt", "r");
    if (!fp) {
        printf("Unable to open file keys.txt\n");
        return;
    }

    char word[MAX];

    printf("\n[Part 1] Inserting keys from file:\n");

    while (fscanf(fp, "%s", word) != EOF) {
        printf("Inserted: %s\n", word);
        insert(root, word);
    }
    fclose(fp);

    char key[MAX];
    printf("\nEnter a word to search (from file keys): ");
    scanf("%s", key);

    if (search(root, key))
        printf("FOUND in trie.\n");
    else
        printf("NOT FOUND.\n");
}

// -------------- PART 2: Read keys from char array ------------
void part2(TrieNode *root) {
    char *keys[] = {"and","bat","ball","book","cot","cotton",
                    "internet","interview","joy","job",
                    "King","Lion","man","mango","manage"};

    int n = sizeof(keys) / sizeof(keys[0]);

    printf("\n\n[Part 2] Inserting keys from char array:\n");
    for (int i = 0; i < n; i++) {
        printf("Inserted: %s\n", keys[i]);
        insert(root, keys[i]);
    }

    char key[MAX];
    printf("\nEnter a word to search (from char array keys): ");
    scanf("%s", key);

    if (search(root, key))
        printf("FOUND in trie.\n");
    else
        printf("NOT FOUND.\n");
}

// -------------- PART 3: Read array keys, search text file keys ----------
void part3(TrieNode *root) {

    char *arrayKeys[] = {"and","bat","ball","book","cot","cotton",
                         "internet","interview","joy","job",
                         "King","Lion","man","mango","manage"};

    int n = sizeof(arrayKeys) / sizeof(arrayKeys[0]);

    printf("\n\n[Part 3] Inserting array keys:\n");
    for (int i = 0; i < n; i++) {
        printf("Inserted: %s\n", arrayKeys[i]);
        insert(root, arrayKeys[i]);
    }

    FILE *fp = fopen("keys.txt", "r");
    if (!fp) {
        printf("Unable to open file keys.txt\n");
        return;
    }

    char word[MAX];
    printf("\nSearching file keys inside trie:\n");

    while (fscanf(fp, "%s", word) != EOF) {
        if (search(root, word))
            printf("%s → FOUND\n", word);
        else
            printf("%s → NOT FOUND\n", word);
    }
    fclose(fp);
}

// ---------------- MAIN ----------------
int main() {
    TrieNode *root = createNode();

    printf("========= TRIE PROGRAM =========\n");
    printf("1. File -> Trie -> Search user input\n");
    printf("2. Array -> Trie -> Search user input\n");
    printf("3. Array -> Trie -> Search file keys\n");

    int choice;
    printf("\nEnter choice (1/2/3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: part1(root); break;
        case 2: part2(root); break;
        case 3: part3(root); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
