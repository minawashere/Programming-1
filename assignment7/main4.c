#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char str[10];
    printf("Enter a string of numbers: ");

    do  {
        scanf("%s", &str);
        if (isdigit(str[0]) || str[0] == '-') break;
        printf("Enter a valid string number\n");
    } while (!(isdigit(str[0]) || str[0] == '-'));


    int x = 0;

    for (int i = str[0] == '-' ? 1 : 0 ; str[i]; i++) {
        if (isdigit(str[i]))
            x = x * 10 + (str[i] - '0') ;
        else break;
    }

    if (str[0] == '-') x *= -1;

    printf("%d\n", x);

}
