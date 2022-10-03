#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int c;
    int charCounter = 0;
    char charArray[100];
    int charCountArray[100] = {0};

    // Loop over every character from the input
    while ((c = getchar()) != EOF)
    {
        // Do not process the char if it is a space or EOL
        if (c != ' ' && c != '\n')
        {
            // Verify that the current char is not in the list
            bool isInArray = false;
            for (int i = 0; i < charCounter; i++)
            {
                if (charArray[i] == c)
                {
                    isInArray = true;
                    charCountArray[i]++;
                    break;
                }
            }
            // If it is not in the list, then add it
            if (!isInArray)
            {
                charArray[charCounter] = c;
                charCountArray[charCounter]++;
                charCounter++;
            }
        }
    }

    for (int i = 0; i < charCounter; i++)
    {
        if (charArray[i] >= 48 && charArray[i] <= 57)
        {
            printf("%c : %d occurences\n", charArray[i], charCountArray[i]);
        }
    }

    for (int i = 0; i < charCounter; i++)
    {
        if (charArray[i] >= 65 && charArray[i] <= 122)
        {
            printf("%c : %d occurences\n", charArray[i], charCountArray[i]);
        }
    }

    return 0;
}