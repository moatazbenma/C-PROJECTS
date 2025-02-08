#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100

void chatBot();
void processInput(char input[]);

int main() {
    chatBot(); // Start the chatbot
    return 0;
}

void chatBot() {
    char input[MAX_INPUT];

    printf("Simple Chatbot - Type 'bye' to exit\n");

    while (1) {
        printf("\nYou: ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = '\0'; 

        if (strcmp(input, "bye") == 0) {
            printf("Bot: Goodbye! Have a nice day!\n");
            break;
        }

        processInput(input);
    }
}

void processInput(char input[]) {
    if (strcmp(input, "hello") == 0) {
        printf("Bot: Hi there! How can I help you?");
    } else if (strcmp(input, "how are you") == 0) {
        printf("Bot: I'm just a program, but I'm doing great! Thanks for asking.");
    } else if (strcmp(input, "what is your name") == 0) {
        printf("Bot: I'm a simple chatbot made in C!");
    } else {
        printf("Bot: Sorry, I don't understand that.");
    }
}
