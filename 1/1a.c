/*Create 3 pointers called P1, P2, P3 and an integer variable X where P1
points to P2, P2 points to P3 and P3 points to X. Demonstrate how to
read and retrieve the value of X using P1, P2 and P3.*/

#include <stdio.h>

void main() {
    int x;
    int *P3, **P2, ***P1;

    P3 = &x;
    P2 = &P3;
    P1 = &P2;

    // reading and printing using P3
    printf("Enter a number:\n");
    scanf("%d", P3);
    printf("Entered number is %d\n", *P3);

    // reading and printing using P2
    printf("Enter a number:\n");
    scanf("%d", *P2);
    printf("Entered number is %d\n", **P2);

    // reading and printing using P1
    printf("Enter a number:\n");
    scanf("%d", **P1);
    printf("Entered number is %d\n", ***P1);
}