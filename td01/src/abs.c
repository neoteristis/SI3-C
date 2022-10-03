#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int val;

    printf("Enter a number: ");
    scanf("%d", &val);

    printf("The absolute value of your number is : %d \n", abs(val));

    return 0;
}