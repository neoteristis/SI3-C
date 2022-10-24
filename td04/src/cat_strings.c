#include <stdio.h>
#include <stdarg.h>

void cat_strings(char str1[], ...)
{
    va_list ap;
    va_start(ap, str1);

    printf("%s", str1);

    char *str2;

    while ((str2 = va_arg(ap, char *)) != NULL)
    {
        printf("%s", str2);
    }
    printf("\n");

    va_end(ap);
}

int main(void)
{
    cat_strings("es", "sai", NULL);
    return 1;
}