#include <stdio.h>
#include <stdarg.h>

float moyenne(int count, ...)
{
    if (!count)
        return 0;

    va_list ap;
    float average = 0.0;

    va_start(ap, count);
    for (int i = 0; i < count; i++)
    {
        float mark = (float)va_arg(ap, double);
        average += mark;
    }
    va_end(ap);

    return average / count;
}

int main(void)
{
    printf("Moyenne1 = %.2f\n", moyenne(2, 10.0, 15.0));
    printf("Moyenne2 = %.2f\n", moyenne(5, 10.0, 15.0, 18.5, 0.0, 3.5));
    printf("Moyenne3 = %.2f\n", moyenne(0));
    return 1;
}