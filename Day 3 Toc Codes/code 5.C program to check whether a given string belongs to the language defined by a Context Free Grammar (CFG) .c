#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool belongsToCFG(char *str) {
    int len = strlen(str);
    int i = 0;

    while (i < len && str[i] == '0')
        i++;

    while (i < len && str[i] == '0')
        i++;

    if (i == len)
        return true;

    while (i < len && str[i] == '1')
        i++;

    if (i == len)
        return true;

    return false;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (belongsToCFG(str))
        printf("The string belongs to the language defined by the CFG.\n");
    else
        printf("The string does not belong to the language defined by the CFG.\n");

    return 0;
}
