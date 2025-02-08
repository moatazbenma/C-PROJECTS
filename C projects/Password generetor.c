#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 50

// Function to generate a random password
void generatePassword(int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    char password[MAX_PASSWORD_LENGTH];

    srand(time(NULL)); // Seed for randomness

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    password[length] = '\0'; // Null-terminate the string

    printf("Generated Password: %s\n", password);
}

int main() {
    int length;
    
    printf("Enter password length: ");
    scanf("%d", &length);

    if (length <= 0 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid length! Choose between 1 and %d.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    generatePassword(length);

    return 0;
}
