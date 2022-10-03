#include <stdio.h>
#include <math.h>

float convertToFahreinheit(float value)
{
    return (9 * value) / 5 + 32;
}

int main(void)
{
    printf("+--------+--------+\n");

    for (float i = 0.0; i <= 20.0; i += 0.5)
    {
        printf("| %dC | %dfF |\n", (int)rint(i), (int)rint(convertToFahreinheit(i)));
    }

    printf("+--------+--------+\n");

    return 0;
}