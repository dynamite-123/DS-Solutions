#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE = 5;

int isFull(int front, int rear) {
    return (rear + 1) % MAX_SIZE == front;
}

int isEmpty(int front, int rear) {
    return front == -1;
}

void insertRear(int *queue, int *front, int *rear, int data) {
    if (isFull(*front, *rear)) {
        printf("Queue overflow\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % MAX_SIZE;
    queue[*rear] = data;
    printf("Element %d inserted\n", data);
}

int deleteFront(int *queue, int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue[*front];
    if (*front == *rear) {
        *front = *rear = -1;
    } else {
        *front = (*front + 1) % MAX_SIZE;
    }
    // Return the dequeued data
    return data;
}

int deleteRear(int *queue, int *front, int *rear) {
    if (isEmpty(*front, *rear)){
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue[*rear];

    if (*front == *rear) {
        *front = *rear = -1;
    }
    else{
        *rear = (*rear - 1) % MAX_SIZE;
    }
    return data;
}

// Function to display the queue elements
void display(int *queue, int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    // Print the last element
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, val;

    int *queue = (int *)malloc(5 * sizeof(int));
    int front = -1, rear = -1;

    printf("Enter\n1->Insert Rear\n2->Delete Front\n3->Delete Rear\n4->Display\n5->Exit\n");

    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d", &val);
                insertRear(queue, &front, &rear, val);
                printf("%d\n%d\n", front, rear);
                break;
            case 2:
                deleteFront(queue, &front, &rear);     
                break;      
            case 3:
                deleteRear(queue, &front, &rear);
                break;
            case 4:
                display(queue, front, rear);
                break;   
            default:
                exit(0);
        }

    }

    return 0;
}