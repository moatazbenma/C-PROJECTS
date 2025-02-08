#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

int taskCounter = 0;
char task[MAX_TASKS][MAX_LENGTH];

void addTasks();
void viewTasks();
void deleteTasks();

int main() {
    int choice;

    while (1) { // Main menu loop
        printf("\n====== To-Do List ======\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after scanf

        switch (choice) {
            case 1:
                addTasks();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTasks();
                break;
            case 4:
                printf("See you later!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void addTasks() {
    if (taskCounter >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }
    printf("Enter the task: ");
    fgets(task[taskCounter], MAX_LENGTH, stdin);
    task[taskCounter][strcspn(task[taskCounter], "\n")] = '\0'; // Remove newline
    taskCounter++;
    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCounter == 0) {
        printf("No tasks to display.\n");
        return;
    }
    printf("\nYour tasks:\n");
    for (int i = 0; i < taskCounter; i++) {
        printf("%d. %s\n", i + 1, task[i]);
    }
}

void deleteTasks() {
    int delete;

    if (taskCounter == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    printf("Enter the task number to delete: ");
    scanf("%d", &delete);

    if (delete < 1 || delete > taskCounter) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = delete - 1; i < taskCounter - 1; i++) {
        strcpy(task[i], task[i + 1]);
    }

    taskCounter--;
    printf("Task deleted successfully!\n");
}
