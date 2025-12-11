#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee{
    char name[50];
    int salary;
    struct Employee *left, *right;
};
struct Employee *create(char *name, int salary)
{
    struct Employee *emp = (struct Employee *)malloc(sizeof(struct Employee));
    strcpy(emp->name, name);
    emp->salary = salary;
    emp->left = emp->right = NULL;
    return emp;
}
struct Employee *insert(struct Employee *root, char *name, int salary)
{
    if (root == NULL)
        return create(name, salary);
    if (salary < root->salary)
        root->left = insert(root->left, name, salary);
    else
        root->right = insert(root->right, name, salary);
    return root;
}
void inorder(struct Employee *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s (%d)\n", root->name, root->salary);
        inorder(root->right);
    }
}
int totalSalary(struct Employee *root)
{
    if (root == NULL)
        return 0;
    return root->salary + totalSalary(root->left) + totalSalary(root->right);
}
struct Employee *findMin(struct Employee *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
struct Employee *findMax(struct Employee *root)
{
    while (root && root->right != NULL)
        root = root->right;
    return root;
}
int main()
{
    struct Employee *root = NULL;
    int choice, salary;
    char name[50];
    printf("=== Employee Database using BST ===\n");
    while (1)
    {
printf("\n1. Insert Employee\n2. Display Employees\n3. Show Total Expense\n4. Show Max/Min Salary\n5. Exit\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
        case 1:
            printf("Enter name and salary: ");
            scanf("%s %d", name, &salary);
            root = insert(root, name, salary);
            printf("Employee added successfully.\n");
            break;
        case 2:
            printf("Employees (sorted by salary):\n");
            inorder(root);
            break;
        case 3:
            printf("Total Monthly Expense: %d\n", totalSalary(root));
            break;
        case 4:
            printf("Max Salary: %s (%d)\n", findMax(root)->name, findMax(root)->salary);
            printf("Min Salary: %s (%d)\n", findMin(root)->name, findMin(root)->salary);
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