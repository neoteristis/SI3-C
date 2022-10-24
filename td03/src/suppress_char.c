#include <stdio.h>

void suppress_char(char str[], char c) {
    int i = 0;
    while (str[i]) {
        if (str[i] == c) {
            int j = i+1;
            while (str[j]) {
                str[j-1] = str[j];
                j++;
            }
            str[j-1] = '\0';
        }
        i++;
    }
}

int main(void) {

    char s1[] = "ceci est un test ou j'enleve tous les e !";

    suppress_char(s1, 'e');

    int i = 0;
    while (s1[i]) {
        printf("%c", s1[i]);
        i++;
    }
    printf("\n");

    return 1;
}