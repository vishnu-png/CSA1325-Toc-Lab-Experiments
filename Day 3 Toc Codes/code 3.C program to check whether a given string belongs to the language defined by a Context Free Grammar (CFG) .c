#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_string(char *str) {
    int len = strlen(str);
    int i = 0;

    // Check if string starts with '0' and ends with '1'
    if (str[0] != '0' || str[len - 1] != '1')
        return false;

    // Iterate through the string
    while (str[i] != '1') {
        // Check if each character is either '0' or '1'
        if (str[i] != '0')
            return false;
        i++;
    }

    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (is_valid_string(str))
        printf("String belongs to the language.\n");
    else
        printf("String does not belong to the language.\n");

    return 0;
}
