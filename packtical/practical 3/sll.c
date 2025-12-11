#include <stdio.h>
#include <stdlib.h>
struct Node{
    int bill;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(int bill){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->bill = bill;
    newNode->next = NULL;
    return newNode;
}
void insertBill(int bill){
    struct Node *newNode = createNode(bill);
    if (head == NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Bill of %d added successfully.\n", bill);
}

void displayBills(){
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("No bills recorded.\n");
        return;
    }
    printf("Bills of the day: ");
    while (temp != NULL)
    {
        printf("%d ", temp->bill);
        temp = temp->next;
    }
    printf("\n");
}

void totalSale(){
    struct Node *temp = head;
    int total = 0;
    while (temp != NULL){
        total += temp->bill;
        temp = temp->next;
    }

    printf("Total Sale of the day: %d\n", total);
}

void maxMinBill(){
    if (head == NULL){
        printf("No bills to analyze.\n");
        return;
    }
    int max = head->bill, min = head->bill;
    struct Node *temp = head->next;
    while (temp != NULL){
        if (temp->bill > max)
            max = temp->bill;
        if (temp->bill < min)
            min = temp->bill;
        temp = temp->next;
    }
    printf("Maximum Bill: %d\n", max);
    printf("Minimum Bill: %d\n", min);
}
int main()
{
    int choice, bill;
    printf("=== Coffee Shop Billing System ===\n");
    while (1)
    {
printf("\n1. Add Bill\n2. Display Bills\n3. Total Sale\n4. Max/Min Bill\n5. Exit\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
        case 1:
            printf("Enter bill amount: ");
            scanf("%d", &bill);
            insertBill(bill);
            break;
        case 2:
            displayBills();
            break;
        case 3:
            totalSale();
            break;
        case 4:
            maxMinBill();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
}
    }
    return 0;
}