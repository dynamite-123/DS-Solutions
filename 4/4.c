/*Develop a menu driven program to implement the follwing operations on array storage representation
i)Insert by position
ii)Delete by position
iii)Insert by key
iv)Delete by key
v)Insert by order
vi)Search by key
vii)Search by position
viii)Reverse the contents*/

#include <stdio.h>
#include <stdlib.h>

int size;

void display(int *, int);
void insert_by_position(int *, int, int, int);
void delete_by_position(int *, int, int);
void insert_by_key(int *, int, int, int);
void delete_by_key(int *, int, int);
void insert_by_order(int *, int, int);
void search_by_key(int *, int, int);
void search_by_position(int *, int, int);
void reverse(int *, int);
void sort(int *, int);

void main() {
    int arr[20];
    int pos, value, n, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        int choice;
        printf("\n1->Insert by position\n2->Delete by position\n3->Insert by key\n4->Delete by key\n5->Insert by order\n6->Search by key\n7->Search by position\n8->Reverse the contents\n9->Exit\nEnter choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the position and value: ");
                scanf("%d%d", &pos, &value);
                insert_by_position(arr, pos, value, n);
                n++;
                printf("Updated array:\n");
                display(arr, n);
                break;
            case 2:
                printf("Enter the position: ");
                scanf("%d", &pos);
                delete_by_position(arr, pos, n);
                n--;
                printf("Updated array:\n");
                display(arr, n);
                break;
            case 3:
                printf("Enter the key and value: ");
                scanf("%d%d", &key, &value);
                insert_by_key(arr, key, value, n);
                n++;
                printf("Updated array:\n");
                display(arr, n);
                break;
            case 4:
                printf("Enter the key: ");
                scanf("%d", &key);
                delete_by_key(arr, key, n);
                n--;
                printf("Updated array:\n");
                display(arr, n);
                break;
            case 5:
                printf("Enter the value: ");
                scanf("%d", &value);
                sort(arr, n);
                insert_by_order(arr, value, n);
                n++;
                display(arr, n);
                break;
            case 6:
                printf("Enter the key: ");
                scanf("%d", &key);
                search_by_key(arr, key, n);
                break;
            case 7:
                printf("Enter the position: ");
                scanf("%d", &pos);
                search_by_position(arr, pos, n);
                break;
            case 8:
                printf("Reversed array: ");
                reverse(arr, n);
                display(arr, n);
                break;
            case 9:
                exit(0);
            default:
                exit(0);
        }
    }
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void insert_by_position(int *arr, int pos, int value, int n) {
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];
    arr[pos] = value;
}

void delete_by_position(int *arr, int pos, int n) {
    for (int i = pos; i < n; i++)
        arr[i] = arr[i + 1];
}

void insert_by_key(int *arr, int key, int value, int n) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i - 1;
            printf("%d\n", pos);
            break;
        }
    }
    insert_by_position(arr, pos, value, n);
}

void delete_by_key(int *arr, int key, int n) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }
    delete_by_position(arr, pos, n);
}

void insert_by_order(int *arr, int value, int n) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (value < arr[i]) {
            pos = i;
            insert_by_position(arr, pos, value, n);
            break;
        }
        if (pos == -1)
            arr[n] = value;
    }
}

void search_by_key(int *arr, int key, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Value found\n");
            return;
        }
    }
    printf("Value not found\n");
}

void search_by_position(int *arr, int pos, int n) {
    if (pos >= n) {
        printf("Value not found\n");
        return;
    }
    printf("Value found\n");
}

void sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void reverse(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }
}
