#include <stdio.h>

float convertToFahreinheit(float value)
{
    return (9 * value) / 5 + 32;
}

int main(void)
{
    printf("+--------+--------+\n");

    for (float i = 0.0; i <= 20.0; i += 0.5)
    {
        printf("| %0.1fC | %0.1fF |\n", i, convertToFahreinheit(i));
    }

    printf("+--------+--------+\n");

    return 0;
}