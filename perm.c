#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to swap characters at positions x and y in a string
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to check if a character has already appeared in the current position
bool shouldSwap(char str[], int start, int current) {
    for (int i = start; i < current; i++) {
        if (str[i] == str[current]) {
            return false;
        }
    }
    return true;
}

// Function to generate and print unique permutations
void permute(char *str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
    } else {
        for (int i = left; i <= right; i++) {
            if (shouldSwap(str, left, i)) {
                swap((str + left), (str + i));
                permute(str, left + 1, right);
                swap((str + left), (str + i)); // backtrack
            }
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);
    printf("All unique permutations of the string are:\n");
    permute(str, 0, n - 1);
    return 0;
}
