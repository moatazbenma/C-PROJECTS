#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void addExpense();
void viewExpense();
void deleteExpense();
void editExpense(); 


struct expense {
    float amount;
    char date[15];
    char category[50];
} expensee[MAX_LENGTH];

int counter = 0;

int main() {
    printf("Personal Expense Tracker By : EL MOUATAZ BENMANSSOUR \n\n\n");

    int choice;
    while (1) {
        printf("\n1. Add Expense \n");
        printf("2. View Expense \n");
        printf("3. Delete Expense\n");
        printf("4. Edit Expense \n");
        printf("5. Exit \n");

        printf("Enter: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpense();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                editExpense();
                break;
            case 5:
                return 0;  
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void addExpense() {
    if (counter >= MAX_LENGTH) {
        printf("Expense list is full!\n");
        return;
    }

    printf("Enter category: ");
    scanf("%s", expensee[counter].category);
    getchar();

    printf("Enter amount: ");
    scanf("%f", &expensee[counter].amount);
    getchar();

    printf("Enter the date: ");
    scanf("%s", expensee[counter].date);

    printf("Expense added successfully!\n");
    counter++;
}

void viewExpense() {
    if (counter == 0) {
        printf("No expenses recorded!\n");
        return;
    }

    for (int i = 0; i < counter; i++) {
        printf("\nExpense #%d\n", i + 1);
        printf("Category: %s\n", expensee[i].category);
        printf("Amount: %.2f\n", expensee[i].amount);
        printf("Date: %s\n", expensee[i].date);
        printf("-----------------------\n");
    }
}

void deleteExpense() {
    if (counter == 0) {
        printf("No expenses to delete!\n");
        return;
    }

    int index;
    printf("Enter the expense number (starting from 1) to delete: ");
    scanf("%d", &index);

    index--;  // Convert to zero-based index

    if (index < 0 || index >= counter) {
        printf("Invalid index! Please enter a valid number.\n");
        return;
    }

    printf("Deleting Expense #%d\n", index + 1);
    printf("Category: %s\n", expensee[index].category);
    printf("Amount: %.2f\n", expensee[index].amount);
    printf("Date: %s\n", expensee[index].date);

    // Shift all elements after the deleted one
    for (int i = index; i < counter - 1; i++) {
        expensee[i] = expensee[i + 1];
    }

    counter--;  // Reduce expense count
    printf("Expense deleted successfully!\n");
}

void editExpense() {
    if (counter == 0) {
        printf("No expenses to edit!\n");
        return;
    }

    int index;
    printf("Enter the expense number (starting from 1) to edit: ");
    scanf("%d", &index);

    index--;  // Convert to zero-based index

    if (index < 0 || index >= counter) {
        printf("Invalid index! Please enter a valid number.\n");
        return;
    }

    printf("Editing Expense #%d\n", index + 1);
    printf("Current Category: %s\n", expensee[index].category);
    printf("Current Amount: %.2f\n", expensee[index].amount);
    printf("Current Date: %s\n", expensee[index].date);

    // Get new values
    printf("\nEnter new category: ");
    scanf("%s", expensee[index].category);
    getchar();

    printf("Enter new amount: ");
    scanf("%f", &expensee[index].amount);
    getchar();

    printf("Enter new date: ");
    scanf("%s", expensee[index].date);

    printf("Expense updated successfully!\n");
}
