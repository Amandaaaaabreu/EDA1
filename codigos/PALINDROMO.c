#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }

    return 1; // Palindrome
}

int main() {
    int N;
    char str[100];

    scanf("%d", &N);
    scanf("%s", str);

    int result = isPalindrome(str);

    printf("%d\n", result);

    return 0;
}