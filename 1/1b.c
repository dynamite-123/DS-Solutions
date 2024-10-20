/*Create a pointer to an integer array, Read and display the contents using
pointer and also display the contents in reverse order using pointer.*/

#include <stdio.h>

void main() {
    int n;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int array[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }

    printf("Array in forward order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");

    printf("Array in reverse order:\n");
    for (int i = n - 1; i > -1; i--) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}