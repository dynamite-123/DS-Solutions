/*d) Create a pointer to two dimensional array of integers. Write functions
Read (P) and Display (P) to read and display the contents using pointer.*/

#include <stdio.h>

void read(int (*p)[3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", *(p + i) + j);
        }
    }
}

void write(int (*p)[3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int a[3][3], (*p)[3];
    p = a;
    printf("Enter 3x3 matrix elements:\n");
    read(p, 3, 3);
    write(p, 3, 3);

    return 0;
}