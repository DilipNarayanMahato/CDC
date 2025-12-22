#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 100

bool isAcceptedByFA(const char *str) {
    int state = 0; // Start state
    char c;

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];

        // Transition based on the current state and input character
        switch (state) {
            case 0: // Start state
                if (c == 'i') state = 1;
                else state = 0;
                break;

            case 1: // After 'i'
                if (c == 'n') state = 2;
                else if (c == 'i') state = 1;
                else state = 0;
                break;

            case 2: // After 'in'
                if (c == 'g') state = 3;
                else if (c == 'i') state = 1;
                else state = 0;
                break;

            case 3: // Accept state (after "ing")
                state = 3; // Stay in accept state
                break;

            default:
                state = 0;
                break;
        }
    }

    return (state == 3); // Accepted if "ing" was found
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string (only alphabetic characters): ");
    
    if (scanf("%99s", input) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Validate and convert to lowercase
    for (int i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            printf("Invalid input! Please enter only alphabetic characters.\n");
            return 1;
        }
        input[i] = tolower(input[i]);
    }

    // Check if string is accepted
    if (isAcceptedByFA(input)) {
        printf("The string \"%s\" is accepted (contains 'ing').\n", input);
    } else {
        printf("The string \"%s\" is not accepted (does not contain 'ing').\n", input);
    }

    return 0;
}
