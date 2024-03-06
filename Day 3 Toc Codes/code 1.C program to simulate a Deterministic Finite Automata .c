#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// DFA transition function
int transition(int currentState, char input) {
    switch (currentState) {
        case 0:
            if (input == 'a')
                return 1;
            else
                return -1; // Invalid transition
        case 1:
            if (input == 'a')
                return 1;
            else
                return -1; // Invalid transition
        default:
            return -1; // Invalid state
    }
}

// DFA simulation
bool isAccepted(char *input) {
    int currentState = 0;
    int len = strlen(input);
    
    for (int i = 0; i < len; i++) {
        currentState = transition(currentState, input[i]);
        if (currentState == -1)
            return false; // Invalid transition
    }
    
    // Check if the final state is reached
    return currentState == 1;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isAccepted(input))
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
