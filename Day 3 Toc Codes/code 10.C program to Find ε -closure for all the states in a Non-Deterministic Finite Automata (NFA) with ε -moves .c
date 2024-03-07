#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10 // Maximum number of states in the NFA


void epsilonClosure(int nfa[][MAX_STATES], int n, int state, bool visited[]) {
    visited[state] = true; // Mark the current state as visited
    
    for (int i = 0; i < n; i++) {
        if (nfa[state][i] == 1 && !visited[i]) {
            epsilonClosure(nfa, n, i, visited); // Recursively find ε-closure for next state
        }
    }
}

void findAllEpsilonClosures(int nfa[][MAX_STATES], int n) {
    printf("ε-Closures for all states:\n");
    for (int i = 0; i < n; i++) {
        bool visited[MAX_STATES] = {false}; // Initialize visited array for each state
        printf("ε-closure(%d): { ", i);
        epsilonClosure(nfa, n, i, visited);
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                printf("%d ", j); // Print the states in the ε-closure
            }
        }
        printf("}\n");
    }
}

int main() {
    int n; // Number of states
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &n);
    
    int nfa[MAX_STATES][MAX_STATES]; // NFA transition table
    
    printf("Enter the NFA transition table (1 for transition, 0 for no transition):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Is there a transition from state %d to state %d? (1/0): ", i, j);
            scanf("%d", &nfa[i][j]);
        }
    }
    
    findAllEpsilonClosures(nfa, n); // Find ε-closure for all states
    
    return 0;
}
