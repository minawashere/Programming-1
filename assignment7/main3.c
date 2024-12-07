#include <stdio.h>
#include <string.h>

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int findFrequency(char* str, char* word) {
    int count = 0;
    int wordLen = strlen(word);

    for (int i = 0; str[i]; i++) {
        if (i != 0 && !is_whitespace(str[i - 1]))
            continue;

            int matches = 1;
            for (int j = 0; word[j]; j++) {
                if (str[i + j] != word[j] || str[i + j] == '\0') {
                    matches = 0;
                    break;
                }
            }
            if (matches && (is_whitespace(str[i + wordLen]) || str[i + wordLen] == '\0')) {
                count++;
                matches = 0;
            }
    }

    return count;
}


int main(void)
{
    char str[100];
    char word[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Enter a word: ");
    scanf("%s", word);

    int freq = findFrequency(str, word);
    printf("%d", freq);
    return 0;
}
