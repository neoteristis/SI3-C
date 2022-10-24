#include <stdio.h>
#include <string.h>

int palindrome(const char str[]) {
    int length = strlen(str);
    for (int i = 0; i <= length / 2; i++) {
        if (str[i] != str[length-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    printf("Palindrome : %d\n", palindrome("ressasser"));
    printf("Palindrome : %d\n", palindrome("kayak") );
    printf("Palindrome : %d\n",palindrome("X"));
    printf("Palindrome : %d\n",palindrome("test"));
    return 1;
}