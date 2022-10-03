#include <stdio.h>
#include <stdbool.h>

int main(void)
{

    char c;
    int charCounter = 0;
    int lineCounter = 1;
    int wordCounter = 1;

    bool isWord = false;

    while ((c = getchar()) != EOF)
    {
        charCounter++;

        if (c == '\n')
        {
            lineCounter++;
        }
        else if (c != '\t' && c != ' ')
        {
            isWord = true;
        }

        if (isWord && (c == '\t' || c == '\n' || c == ' '))
        {
            isWord = false;
            wordCounter++;
        }
    }

    printf("lines: %d\n", lineCounter);
    printf("words: %d\n", wordCounter);
    printf("chars: %d\n", charCounter);

    return 0;
}