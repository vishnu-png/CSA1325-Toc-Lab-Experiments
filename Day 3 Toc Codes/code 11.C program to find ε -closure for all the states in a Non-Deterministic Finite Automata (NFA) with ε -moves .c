#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10

// Structure to represent the transitions of the NFA
struct Transition {
    int nextState;
    char symbol;
};

// Structure to represent a state in the NFA
struct State {
    int id;
    struct Transition transitions[MAX_STATES];
    int numTransitions;
};

// Function to find ε-closure for a state
void epsilonClosure(struct State nfa[], int state, bool visited[]) {
    // Mark the current state as visited
    visited[state] = true;
    
    // Traverse through transitions of current state
    for (int i = 0; i < nfa[state].numTransitions; i++) {
        int nextState = nfa[state].transitions[i].nextState;
        
        // If the transition is an epsilon transition and the next state is not visited yet
        if (nfa[state].transitions[i].symbol == 'e' && !visited[nextState]) {
            // Recursively find epsilon closure for next state
            epsilonClosure(nfa, nextState, visited);
        }
    }
}

int main() {
    int numStates, numSymbols;

    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    // Creating an array of states
    struct State nfa[numStates];

    // Taking input for transitions
    for (int i = 0; i < numStates; i++) {
        int numTransitions;
        printf("Enter the number of transitions for state %d: ", i);
        scanf("%d", &numTransitions);
        nfa[i].id = i;
        nfa[i].numTransitions = numTransitions;
        printf("Enter transitions for state %d in the format nextState symbol (e for epsilon):\n", i);
        for (int j = 0; j < numTransitions; j++) {
            scanf("%d %c", &nfa[i].transitions[j].nextState, &nfa[i].transitions[j].symbol);
        }
    }

    // Finding epsilon closure for each state
    printf("\nEpsilon Closures:\n");
    for (int i = 0; i < numStates; i++) {
        bool visited[numStates];
        for (int j = 0; j < numStates; j++) {
            visited[j] = false;
        }

        printf("ε-closure(%d): ", nfa[i].id);
        epsilonClosure(nfa, nfa[i].id, visited);

        // Printing epsilon closure for current state
        for (int j = 0; j < numStates; j++) {
            if (visited[j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
