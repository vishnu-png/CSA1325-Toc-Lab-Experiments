#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool belongsToCFG(char *str) {
    int len = strlen(str);
    int i = 0;

    while (i < len) {
      
        if (str[i] == '0') {
            i++;
            while (i < len && str[i] == '0') {
                i++;
            }
            
            if (i < len && str[i] == '1') {
                i++;
            } else {
                return false;
            }
        }
        
        else if (str[i] == '1') {
            return false;
        }
        
        else {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    
    if (belongsToCFG(str)) {
        printf("String \"%s\" belongs to the CFG language.\n", str);
    } else {
        printf("String \"%s\" does not belong to the CFG language.\n", str);
    }
    
    return 0;
}
