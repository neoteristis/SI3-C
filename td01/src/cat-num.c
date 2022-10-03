#include <stdio.h>

int main(void)
{
    int c;
    int counter = 1;

    printf("%d ", counter);

    while ((c = getchar()) != EOF)
    {
        putchar(c);
        if (c == '\n')
        {
            printf("%d ", ++counter);
        }
    }

    printf("\n");

    return 0;
}