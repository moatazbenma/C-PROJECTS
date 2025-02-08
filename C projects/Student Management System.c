#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

struct student {
    char name[100];
    int studentNumber;
} student[MAX_LENGTH];

int studentCounter = 0;

void addStudent();
void viewStudent();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n1. Add student\n");
        printf("2. View students\n");
        printf("3. Search student\n");
        printf("4. Delete student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void addStudent() {
    if (studentCounter >= MAX_LENGTH) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(student[studentCounter].name, 100, stdin);
    student[studentCounter].name[strcspn(student[studentCounter].name, "\n")] = '\0'; // Remove newline

    printf("Enter student number: ");
    scanf("%d", &student[studentCounter].studentNumber);

    printf("Student added successfully!\n");
    studentCounter++;
}

void viewStudent() {
    if (studentCounter == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent List:\n");
    for (int i = 0; i < studentCounter; i++) {
        printf("Name: %s, Number: %d\n", student[i].name, student[i].studentNumber);
    }
}

void searchStudent() {
    int studentNumber, found = 0;
    printf("Enter student number to search: ");
    scanf("%d", &studentNumber);

    for (int i = 0; i < studentCounter; i++) {
        if (student[i].studentNumber == studentNumber) {
            printf("Student found!\n");
            printf("Name: %s\n", student[i].name);
            printf("Number: %d\n", student[i].studentNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void deleteStudent() {
    int studentNumber, i, found = 0;
    printf("Enter student number to delete: ");
    scanf("%d", &studentNumber);

    for (i = 0; i < studentCounter; i++) {
        if (student[i].studentNumber == studentNumber) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < studentCounter - 1; i++) {
            // Using strcpy to copy the name field
            strcpy(student[i].name, student[i + 1].name);
            // Copy the student number manually
            student[i].studentNumber = student[i + 1].studentNumber;
        }
        studentCounter--;
        printf("Student deleted successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}
