#include <stdio.h>

int indice(const char str[], const char c) {
    int i = 0;
    while (str[i]) {
        if (str[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

int indice_droite(const char str[], const char c) {
    int i = 0;
    int output = -1;
    while (str[i]) {
        if (str[i] == c) {
            output = i;
        }
        i++;
    }
    return output;
}

int main(void) {
    printf("Value : %d\n", indice("Test", 'T'));
    printf("Value : %d\n", indice("Test", 't'));
    printf("Value : %d\n", indice("Test", 'z'));
    printf("Value : %d\n", indice("Tester", 'e'));
    printf("Value : %d\n", indice_droite("Test", 'T'));
    printf("Value : %d\n", indice_droite("Test", 't'));
    printf("Value : %d\n", indice_droite("Test", 'z'));
    printf("Value : %d\n", indice_droite("Tester", 'e'));
    return 1;
}