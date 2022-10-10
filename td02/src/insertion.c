#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void insertion(int array[], int nbValue, int valueToInsert)
{
    if (nbValue == 0)
        array[0] = valueToInsert;
    else
    {
        for (int i = nbValue; i >= 0; i--)
        {
            if (array[i - 1] > valueToInsert)
            {
                array[i] = array[i - 1];
            }
            else
            {
                array[i] = valueToInsert;
                break;
            }
        }
    }
}

int main(void)
{
    const int MAX = 10;
    int array[MAX] = {0};
    int nbValue = 0;

    char c;

    bool isNumber = false;
    char currentDigits[10];
    int digitCounter = 0;
    int currentNumber = 0;

    while (true)
    {
        c = getchar();

        if (c != '\t' && c != ' ' && c != EOF && c != '\0' && c != '\n')
        {
            isNumber = true;
            currentDigits[digitCounter] = c;
            digitCounter++;
        }

        if (isNumber && (c == '\t' || c == ' ' || c == EOF))
        {
            isNumber = false;

            // Loop over every digit found to create the correct number from those
            for (int i = 0; i < digitCounter; i++)
            {
                currentNumber += (currentDigits[i] - '0') * pow(10, digitCounter - 1 - i);
            }

            printf("Current digits : ");
            for (int i = 0; i < digitCounter; i++)
            {
                printf("%c", currentDigits[i]);
            }
            printf("\n");

            // Insert the number in the array and increment the number of values in it
            insertion(array, nbValue, currentNumber);
            nbValue++;

            // Reset the value for the next loop
            digitCounter = 0;
            currentNumber = 0;
        }

        if (c == EOF)
        {
            break;
        }
    }

    // Display the table
    printf("--- Display the table ---\n");
    for (int i = 0; i < nbValue; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}