#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int counter = 0;
    int userInput;
    bool stop = false;

    while (!stop)
    {
        printf("Enter a number: ");
        scanf("%d", &userInput);

        if (userInput >= 0)
        {
            counter++;
        }
        else
        {
            stop = true;
        };
    };
    printf("You entered %d positive numbers\n", counter);

    return 0;
}