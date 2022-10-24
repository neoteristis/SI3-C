#include <stdio.h>
#include <string.h>

int Strstr(const char a[], char b[]) {
    int length_a = strlen(a);
    int length_b = strlen(b);

    if (length_a < length_b) return 0;
    
    int i = 0;
    while (a[i+length_b-1]) {
        for (int j = 0; j < length_b; j++) {
            if (a[i+j] != b[j]) {
                break;
            }
            if (j == length_b - 1) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    // Test of the method Strstr()
    /*
    printf("Result : %d\n", Strstr("ceci est du texte", "ceci est du texte"));
    printf("Result : %d\n", Strstr("ceci est du texte", "ceci"));
    printf("Result : %d\n", Strstr("ceci est du texte", "est"));
    printf("Result : %d\n", Strstr("ceci est du texte", "du"));
    printf("Result : %d\n", Strstr("ceci est du texte", "texte"));
    printf("Result : %d\n", Strstr("ceci est du texte", "i es"));
    printf("Result : %d\n", Strstr("ceci est du texte", "pas"));
    printf("Result : %d\n", Strstr("ceci est du texte", "nope"));
    printf("Result : %d\n", Strstr("ceci est du texte", "haha"));
    printf("Result : %d\n", Strstr("ceci est du texte", "hahahahahahahahahah"));
    printf("Result : %d\n", Strstr("ceci est du texte", "123454647"));
    */

    char str[256];
    while (fgets(str, 256, stdin)) { // read each line from the file from stdin
        if (Strstr(str, argv[1])) {
            printf("%s", str);
        }
    }
           
    return 1;
}