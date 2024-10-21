/*e) Create two pointer called PS1 and PS2 to two strings, Read the contents
using pointers and also write a function StrCat (PS1, PS2) which
concatenates second string to the end of first string using pointers PS1
and PS2.*/

#include <stdio.h>

void main() {
    char str1[25], str2[25], *PS1 = str1, *PS2 = str2;

    printf("Enter string 1: ");
    scanf("%s", PS1);

    printf("Enter string 2: ");
    scanf("%s", PS2);

    void StrCat(char *, char *);

    StrCat(PS1, PS2);

    printf("Concatenated string: %s", PS1);
}

void StrCat(char *str1, char *str2) {
    int i, j;

    // Find the null terminator in str1
    for (i = 0; str1[i] != '\0'; i++) {
    }

    // Concatenate str2 to str1
    for (j = 0; str2[j] != '\0'; j++) {
        str1[i + j] = str2[j];
    }

    // Add the null terminator to the concatenated string
    str1[i + j] = '\0';
}
