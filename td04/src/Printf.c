#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

void print_number_to_base(int base, int number)
{
    if (number < 0)
    {
        putchar('-');
        number *= -1;
    }

    // LE faire avec un ternaire
    if (number < base)
    {
        if (number < 10)
        {
            putchar(number + '0');
        }
        else
        {
            putchar(number - 10 + 'A');
        }
    }
    else
    {
        int remainder = number % base;
        // printf("Number : %d\n", remainder);
        // printf("quotient : %d\n", number / base);
        print_number_to_base(base, number / base);
        putchar(remainder + '0');
    }
}

void print_char_array(char *array)
{
    for (int i = 0; i < strlen(array); i++)
    {
        putchar(array[i]);
    }
}

void Printf(char format[], ...)
{
    va_list ap;
    va_start(ap, format);

    int special_char = 0;
    int size = strlen(format);

    char current_char;
    for (int i = 0; i < size; i++)
    {
        current_char = format[i];

        // It means that the next one will be a special character to consider
        if (current_char == '%' && !special_char)
        {
            special_char = 1;
            continue; // because we do not need to do anything with this character
        }

        if (special_char)
        {
            // we suppose that it is enough to store a float
            // defined here because we can't define it in the case
            char buffer[40];

            switch (current_char)
            {
            case '%':
                putchar('%');
                break;
            case 'd':
                print_number_to_base(10, va_arg(ap, int));
                break;
            case 'x':
                print_number_to_base(16, va_arg(ap, int));
                break;
            case 'f':
                snprintf(buffer, 40, "%f", va_arg(ap, char *));
                printf("%s", buffer);
                break;
            case 'c':
                putchar(va_arg(ap, char));
                break;
            case 's':
                print_char_array(va_arg(ap, char *));
                break;
            default:
                putchar('%');
                putchar(current_char);
            }

            special_char = 0;
        }
        // We can just put the character because it's a normal one
        else
        {
            putchar(current_char);
        }
    }

    // Manage the case when the % is at the end of the array
    if (current_char == '%')
    {
        putchar(current_char);
    }

    va_end(ap);
}

int main()
{
    Printf("DEBUT\n%s%c c'est moi.\nTest nombres: 0x%x et %d et un négatif %d\n",
           "salut", ',', 161, 123, -12);
    Printf("Trois nombres sur la même ligne: %d %f %d\n", 1, 2.0, 3);
    Printf("Affichage d'un '%c' et encore un d'une autre façon '%%'\n", '%');
    Printf("Affichage d'un %% non suivi d'un caractère spécial ==> %z...\n");
    Printf("Attention au %% en fin de la chaîne format ==> %");
    Printf("\nFIN\n");
    return 1;
}