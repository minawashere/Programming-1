#include <stdio.h>
#include <stdlib.h>

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

char* strstr (char *str, char *word) {
    for (int i = 0; str[i]; i++) {
        if (i != 0 && !is_whitespace(str[i - 1]))
            continue;

        int matches = 1;
        int j;
        for (j = 0; word[j]; j++) {
            if (str[i + j] != word[j] || str[i + j] == '\0') {
                matches = 0;
                break;
            }
        }
        if (matches && (is_whitespace(str[i + j]) || str[i + j] == '\0')) {
            return &str[i];
        }
    }
}


int main() {
    char str[100];
    char word[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Enter a word: ");
    scanf("%s", word);

    char* x = strstr(str, word);
    printf("%s", x);
    return 0;
}