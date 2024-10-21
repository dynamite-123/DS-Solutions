/*Create a pointer to two dimensional array of integers. Write functions
Read (P) and Display (P) to read and display the contents using pointer.*/

#include<stdio.h>

void main() {
    int m, n;

    printf("Enter the order of the matrix: ");
    scanf("%d%d", &m, &n);

    int matrix[m][n];

    void Read(int *p, int m, int n);
    void Display(int *p, int m, int n);

    Read(matrix, m, n);
    Display(matrix, m, n);


}

void Read(int *p, int m,int n) {
    printf("Enter the elements:\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            scanf("%d", *(p + i) + j);
        }
    }
}

void Display(int *p, int m,int n) {
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}