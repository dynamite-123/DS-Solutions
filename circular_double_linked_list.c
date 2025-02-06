#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next, *prev;
};

typedef struct node NODE;

NODE *createNode(int value) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->val = value;
    temp->next = temp->prev = NULL;
    return temp;
}

NODE *insertFront(NODE *head, int value) {
    NODE *temp = createNode(value);
    head->val++;

    if (head->next == head) {
        head->next = head->prev = temp;
        temp->next = temp->prev = head;
        return head;
    }
    temp->next = head->next;
    temp->prev = head;
    head->next->prev = temp;
    head->next = temp;
    return head;
}

NODE *insertRear(NODE *head, int value) {
    NODE *temp = createNode(value);
    head->val++;

    if (head->next == head) {
        head->next = head->prev = temp;
        temp->next = temp->prev = head;
        return head;
    }

    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    return head;
}

void display(NODE *head) {
    NODE *cur = head->next;
    printf("LINKED LIST ELEMENTS:\n");
    while (cur != head) {
        printf("%d\t", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

void main() {
    NODE *head = createNode(0);  // - head->val contains the number of nodes
    head->next = head->prev = head;

    int val, choice;

    printf("1->Insert Front\n2->Insert Rear\n3->Display\n4->Exit\n");

    while(1){            
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element to be inserted: \n");
                scanf("%d", &val);
                head = insertFront(head, val);
                break;
            case 2:
                printf("Enter element to be inserted: \n");
                scanf("%d", &val);
                head = insertRear(head, val);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid choice\n");
            
        }
    }
}
