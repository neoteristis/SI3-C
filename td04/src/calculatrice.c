#include <stdio.h>
#include <stdarg.h>

int evaluer(char operateur, int operande, ...)
{
    va_list ap;
    va_start(ap, operande);

    int result = operande;
    int num;

    while ((num = va_arg(ap, int)) != -1)
    {
        switch (operateur)
        {
        case '+':
            result += num;
            break;
        case '-':
            result -= num;
            break;
        case '*':
            result *= num;
            break;
        case '/':
            result /= num;
            break;
        default:
            break;
        }
    }

    va_end(ap);
    return result;
}

int main(void)
{
    printf("%d\n", evaluer('+', 1, 2, 3, -1));
    printf("%d\n", evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1));
    return 1;
}