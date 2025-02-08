#include <stdio.h>
#include <ctype.h> // For toupper function

void display_question(char *question, char *options[], char correct_option) {
    printf("\n%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, options[i]);
    }
    printf("Enter your answer (A, B, C, or D): ");
}

int main() {
    char *questions[] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "What is 10 + 5?",
        "Who wrote 'Romeo and Juliet'?"
    };

    char *options[][4] = {
        {"Paris", "Berlin", "Madrid", "Rome"},
        {"Earth", "Mars", "Jupiter", "Saturn"},
        {"12", "14", "15", "16"},
        {"William Shakespeare", "Charles Dickens", "Mark Twain", "Jane Austen"}
    };

    char correct_answers[] = {'A', 'B', 'C', 'A'};
    int total_questions = 4;
    int score = 0;

    printf("Welcome to the Quiz Game!\n");
    printf("-------------------------\n");

    for (int i = 0; i < total_questions; i++) {
        display_question(questions[i], options[i], correct_answers[i]);

        char user_answer;
        scanf(" %c", &user_answer); // Read user input with a space to consume any trailing newline
        user_answer = toupper(user_answer); // Convert input to uppercase

        if (user_answer == correct_answers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n", correct_answers[i]);
        }
    }

    printf("\nQuiz Over! Your final score is %d out of %d.\n", score, total_questions);

    if (score == total_questions) {
        printf("Excellent! You're a quiz master!\n");
    } else if (score >= total_questions / 2) {
        printf("Good job! Keep practicing!\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}
