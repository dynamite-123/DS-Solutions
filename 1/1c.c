/*Create a pointer to an integer array and pass this as parameter to a
function called Reverse which reverses the array contents using pointer.
Write different functions called Read (P) to read the array elements
using pointer P and Display (P) to display the array contents using P
before and after reverse.*/

#include <stdio.h>

void main(){
    int n;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int array[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    void reverse_array(int *array, int size); //function prototype
    reverse_array(array, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

void reverse_array(int *array, int size_of_array){
    int temp;
    for(int i=0; i<size_of_array/2; i++){
        temp = array[i];
        array[i] = array[size_of_array - 1 - i];
        array[size_of_array - 1 - i] = temp;
    }
}