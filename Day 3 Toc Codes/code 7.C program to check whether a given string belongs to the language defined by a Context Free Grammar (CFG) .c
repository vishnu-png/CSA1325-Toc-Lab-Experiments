#include <stdio.h>
#include <string.h>

int belongsToLanguage(char *str, int start, int end) {
    if (start > end) {
        return 1; // The string belongs to the language
    }

    if (str[start] == '1' && str[end] == '1' && start + 2 == end) {
        return belongsToLanguage(str, start + 1, end - 1); // Checking the part in between
    }

    if (str[start] == '0' && str[end] == '0') {
        return 0; // Cannot start and end with 0
    }

    if ((str[start] == '0' && str[end] == '1') || (str[start] == '1' && str[end] == '0')) {
        return 0; // Cannot start with 0 and end with 1, or vice versa
    }

    if (str[start] == '0') {
        return belongsToLanguage(str, start + 1, end); // Move to the next character
    } else if (str[start] == '1') {
        int i;
        for (i = start + 1; i <= end; i++) {
            if (str[i] == '0') {
                return belongsToLanguage(str, i, end); // Recursively check the remaining part
            }
        }
        return 0; // No 0 found after 1
    }

    return 0; // If none of the conditions match
}

int isBelongToCFG(char *str) {
    int length = strlen(str);
    if (length < 5) {
        return 0; // Strings less than 5 characters cannot belong to the language
    }

    if (str[0] != '0' || str[length - 1] != '0') {
        return 0; // The string must start and end with 0
    }

    return belongsToLanguage(str, 0, length - 1);
}

int main() {
    char str[100];

    printf("Enter a string to check whether it belongs to the language defined by the CFG (S -> A101A, A -> 0A | 1A | ε):\n");
    scanf("%s", str);

    if (isBelongToCFG(str)) {
        printf("The string \"%s\" belongs to the language defined by the CFG.\n", str);
    } else {
        printf("The string \"%s\" does not belong to the language defined by the CFG.\n", str);
    }

    return 0;
}
