#include <stdio.h>
#include <string.h>

// Define maximum number of accounts
#define MAX_ACCOUNTS 100

// Structure to hold account information
struct Account {
    int accountNumber;
    char name[100];
    double balance;
};

// Global variables
struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void createAccount();
void viewAccount();
void depositMoney();
void withdrawMoney();

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\n===== Banking System =====\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }

    struct Account newAccount;

    // Get account details from user
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder's name: ");
    getchar(); // Clear the input buffer
    fgets(newAccount.name, 100, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = '\0'; 
    newAccount.balance = 0.0; // Initial balance is zero

    // Add new account to the global array
    accounts[accountCount++] = newAccount;

    printf("Account created successfully!\n");
}


void viewAccount() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("\nAccount Details:\n");
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found!\n");
}


void depositMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("Invalid deposit amount!\n");
                return;
            }

            accounts[i].balance += amount;
            printf("Deposit successful! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found!\n");
}

void withdrawMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("Invalid withdrawal amount!\n");
                return;
            }

            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
                return;
            }

            accounts[i].balance -= amount;
            printf("Withdrawal successful! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found!\n");
}
