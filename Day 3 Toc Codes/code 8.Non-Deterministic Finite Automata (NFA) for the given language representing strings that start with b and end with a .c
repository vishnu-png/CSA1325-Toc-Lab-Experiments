#include <stdio.h>
#include <stdbool.h>

// Function to simulate the NFA
bool simulateNFA(char *str) {
    // Initial state
    int currentState = 0;
    // Loop through each character in the input string
    for (int i = 0; str[i] != '\0'; i++) {
        char input = str[i];
        // Transition function
        switch (currentState) {
            case 0:
                if (input == 'b')
                    currentState = 1;
                break;
            case 1:
                if (input == 'b' || input == 'a')
                    currentState = 1;
                else
                    currentState = 2;
                break;
            case 2:
                if (input == 'a')
                    currentState = 3;
                break;
            case 3:
                if (input == 'a')
                    currentState = 3;
                break;
        }
    }
    // Check if the final state is reached
    return currentState == 3;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    // Check if the string satisfies the language
    if (simulateNFA(str))
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}
