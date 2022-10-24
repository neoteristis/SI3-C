#include <stdio.h>

void strcpy(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] && s2[i]) {
        s1[i] = s2[i];
        i++;
    }
}

int strcmp(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] < s2[i]) return -1;
        else if (s1[i] > s2[i]) return 1;
        i++;
    }
    if (!s1[i] && !s2[i]) return 0;
    if (!s1[i]) return -1;
    if (!s2[i]) return 1;
}

void strupper(char s[]) {
    int i = 0;
    while (s[i]) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
        i++;
    }
}

int main(void) {
    // Test the strcpy method
    char s1[] = "aaaaaa";
    char s2[] = "bbb";
    strcpy(s1, s2);

    printf("Strcpy : %s\n", s1);

    // Test the strcmp method
    printf("Equal : %d\n", strcmp("z", "abc"));
    printf("Equal : %d\n", strcmp("abc", "z"));
    printf("Equal : %d\n", strcmp("abc", "abd"));
    printf("Equal : %d\n", strcmp("trié", "triée"));
    printf("Equal : %d\n", strcmp("raphael", "raphael"));
    printf("Equal : %d\n", strcmp("abcdefgh", "abcdefghi"));

    // Test the strup method
    char s3[] = "salut";
    char s4[] = "SaLuT";
    char s5[] = "SALUT";
    char s6[] = "salUT";
    char s7[] = ",,salut;;";
    
    strupper(s3);
    strupper(s4);
    strupper(s5);
    strupper(s6);
    strupper(s7);

    printf("Strup : %s\n", s3);
    printf("Strup : %s\n", s4);
    printf("Strup : %s\n", s5);
    printf("Strup : %s\n", s6);
    printf("Strup : %s\n", s7);

    return 0;
}