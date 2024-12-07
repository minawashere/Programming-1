#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i <= len / 2; i++)
        if (str[i] != str[len - i - 1])
            return 0;
    return 1;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    for (int i = 0; str[i]; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
        if (str[i] == '\n')
            str[i] = '\0';
    }

    char* token = strtok(str, " ");

    char max[20];
    char min[20];
    int len = strlen(token);

    strcpy(max, token);
    strcpy(min, token);

    int maxlen = len;
    int minlen = len;

    while (token) {
        if (!checkPalindrome(token)) {
            token = strtok(NULL, " ");
            continue;
        }
        int len = strlen(token);

        if (len > maxlen) {
            strcpy(max, token);
            maxlen = len;
        } else if (len < minlen) {
            strcpy(min, token);
            minlen = len;
        }
        token = strtok(NULL, " ");
    }

    printf("Max palindrome: %s\n", max);
    printf("Min palindrome: %s\n", min);
    return 0;
}
