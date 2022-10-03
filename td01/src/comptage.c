#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int counter = 0;
    int userInput;
    bool stop = false;
    int max = 0;
    int sum = 0;

    while (!stop)
    {
        printf("Enter a number: ");
        scanf("%d", &userInput);

        if (userInput >= 0)
        {
            counter++;
            sum += userInput;
            if (userInput > max)
            {
                max = userInput;
            };
        }
        else
        {
            stop = true;
        }
    }
    printf("The maximum of the %d positive numbers entered is : %d. The sum is : %d.\n", counter, max, sum);

    return 0;
}