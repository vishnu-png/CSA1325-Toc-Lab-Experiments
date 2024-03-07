#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STATES 3 // Number of states in the NFA

// Transition function for the NFA
int transitionTable[STATES][2][STATES] = {
    {{0, 1}, {0, -1}}, // Transition from state 0
    {{-1, 1}, {-1, -1}}, // Transition from state 1
    {{-1, -1}, {-1, 2}} // Transition from state 2
};

// Function to simulate NFA
bool simulateNFA(char *input) {
    int currentState = 0; // Start from initial state
    int inputLength = strlen(input);
    
    for (int i = 0; i < inputLength; i++) {
        int symbolIndex;
        if (input[i] == 'o')
            symbolIndex = 0;
        else if (input[i] == '1')
            symbolIndex = 1;
        else
            return false; // Invalid input character
        
        // Get next state(s) from transition table
        currentState = transitionTable[currentState][symbolIndex][0];
        if (currentState == -1) // If no transition defined for this input
            return false;
        
        // Check for epsilon transitions
        if (transitionTable[currentState][symbolIndex][1] != -1) {
            currentState = transitionTable[currentState][symbolIndex][1];
        }
    }
    
    // Check if the final state is an accepting state
    return currentState == 2;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Call the simulateNFA function and print the result
    if (simulateNFA(input))
        printf("String accepted\n");
    else
        printf("String rejected\n");

    return 0;
}
