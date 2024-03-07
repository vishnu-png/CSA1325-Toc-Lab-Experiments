#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_string(char *str);

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (is_valid_string(str))
        printf("The string belongs to the language defined by the CFG.\n");
    else
        printf("The string does not belong to the language defined by the CFG.\n");

    return 0;
}

bool is_valid_string(char *str) {
    int len = strlen(str);
    int i = 0;

    while (i < len) {
        if (str[i] == '0') {
            int count = 1;
            i++;

            while (i < len && str[i] == '0') {
                count++;
                i++;
            }

            if (i >= len || count != 2) // if the count is not 2 or it's at the end of the string
                return false;

            while (i < len && str[i] == '1') {
                count--;
                i++;
            }

            if (count != 1 || i >= len)
                return false;
        } else if (str[i] == '1') {
            int count = 1;
            i++;

            while (i < len && str[i] == '1') {
                count++;
                i++;
            }

            if (i >= len || count != 2)
                return false;

            while (i < len && str[i] == '0') {
                count--;
                i++;
            }

            if (count != 1 || i >= len)
                return false;
        } else {
            return false;
        }
    }

    return true;
}
