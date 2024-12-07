#include <stdio.h>

int main()
{
    printf("Enter string: ");
    char str[100];
    fgets(str, 100, stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] != ' ' && str[i - 1] == ' ') || i == 0) // str[i - 1] to handle multiple following spaces
        {
            for (int j = i; str[j] != '\0'; j++)
                str[j] = str[j + 1];
        }
    }
    printf("%s\n", str);
    return 0;
}
