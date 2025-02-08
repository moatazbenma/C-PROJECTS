#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

void addStudent();
void displayStudent();
void updateStudent();
void deleteStudent();

typedef struct student {
    int id;
    float grade;
    char name[50];
} student;

int main() {
    int choice;
    
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Bye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

void addStudent() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    student s;
    printf("Enter the ID: ");
    scanf("%d", &s.id);
    getchar(); // Consume newline

    printf("Enter the name: ");
    scanf("%49s", s.name);
    getchar(); // Consume newline

    printf("Enter the grade: ");
    scanf("%f", &s.grade);

    fwrite(&s, sizeof(student), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

void displayStudent() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    student s;
    printf("\nID\tName\tGrade\n");
    printf("-----------------------\n");
    while (fread(&s, sizeof(student), 1, file)) {
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.grade);
    }

    fclose(file);
}

void updateStudent() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    student s;
    while (fread(&s, sizeof(student), 1, file)) {
        if (s.id == id) {
            printf("Enter new Name: ");
            scanf("%49s", s.name);
            printf("Enter new Grade: ");
            scanf("%f", &s.grade);

            fseek(file, -sizeof(student), SEEK_CUR);
            fwrite(&s, sizeof(student), 1, file);
            found = 1;
            break;
        }
    }

    fclose(file);
    
    if (found) {
        printf("Student updated successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}

void deleteStudent() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    student s;
    while (fread(&s, sizeof(student), 1, file)) {
        if (s.id != id) {
            fwrite(&s, sizeof(student), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Student deleted successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}
