#include <stdio.h>
#include <string.h>

int main() {
    char d[] = "hbbdbdbau";
    char e[20];
    int j = 0;  // Index for array 'e'

    for (int i = 0; d[i] != '\0'; i++) {
        int isDuplicate = 0;  // Flag to check if the character is a duplicate

        for (int a = i + 1; d[a] != '\0'; a++) {
            if (d[i] == d[a]) {
                isDuplicate = 1;  // Set the flag if a duplicate is found
                break;  // Exit the loop since we found a duplicate
            }
        }

        if (!isDuplicate) {
            e[j] = d[i];
            j++;
        }
    }

    e[j] = '\0';  // Null-terminate the resulting string
    printf("%s", e);

    return 0;
}

