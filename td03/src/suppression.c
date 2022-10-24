#include <stdio.h>
#include <string.h>

void shift(char str[], int index, int shift) {
    if (!index){
        for (int i = index; i < strlen(str); i++) {
            str[i] = str[i+shift];
        }
    }
    str[strlen(str)] = '\0';
}

void suppression(char str[], const char suppr[]) {
    int length_str = strlen(str);
    int length_suppr = strlen(suppr);

    if (length_str < length_suppr) return;
    
    int i = 0;
    while (str[i+length_suppr-1]) {
        for (int j = 0; j < length_suppr; j++) {
            if (str[i+j] != suppr[j]) {
                break;
            }
            if (j == length_suppr - 1) {
                shift(str, i, length_suppr);
            }
        }
        i++;
    }
}

int main(void) {
    char str1[] = "Ceci est un message dans lequel je vais enlever un mot";
    suppression(str1, "Ceci est un message dans lequel je vais enlever un mot");
    printf("Without the whole message : %s\n\n", str1);

    char str2[] = "Ceci est un message dans lequel je vais enlever un mot";
    suppression(str2, "Ceci est un");
    printf("Without 'Ceci est un': %s\n\n", str2);
    
    char str3[] = "Ceci est un message dans lequel je vais enlever un mot";
    suppression(str3, "n message da");
    printf("Without 'n message da' : %s\n\n", str3);
    
    char str4[] = "Ceci est un message dans lequel je vais enlever un mot";
    suppression(str4, "lequel");
    printf("Without 'lequel': %s\n\n", str4);
    
    char str5[] = "Ceci est un message dans lequel je vais enlever un mot";
    suppression(str5, "je vais");
    printf("Without 'je vais': %s\n\n", str5);
    
    char str6[] = "Ceci est un message dans lequel je vais enlever un mot";
    suppression(str6, "c'est pas dans la chaine");
    printf("Without c'est pas dans la chaine: %s\n\n", str6);
    
    return 1;
}