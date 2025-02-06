/*5) Develop a menu driven program to implement singly linked list with various operations such as
i. Insertion and Deletion at front/rear
ii. Insertion and Deletion at the specified position
iii. Delete by Key
iv. Search by key
v. Create an ordered list
vi. Reverse a list
vii. Creating a copy of the list*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node NODE;
NODE* insertAtPosition(NODE* head, int val, int pos);
NODE* deleteAtPosition(NODE* head, int pos);
NODE* createNode(int data);

void main() {
}

NODE* createNode(int input_data) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = input_data;
    return temp;
}

NODE* insertAtPosition(NODE* head, int val, int pos) {
    if (!head) {
        printf("head cannot be NULL\n");
        return;
    }

    NODE* newNode = createNode(val);

    if (pos = 1) {
        newNode->link = head;
        head = newNode;
        return head;
    }

    NODE* temp = head;
    int count = 1;
    while (count < pos - 1) {
        temp = temp->link;
        count++;
    }

    if (!temp) {
        printf("invalid position\n");
        return head;
    }

    newNode->link = temp->link;
    temp->link = newNode;
    return head;
}

NODE* deleteAtPosition(NODE* head, int pos){
    if(!head){
        printf("head can't be NULL\n");
        return;
    }

    NODE* curr = head;
    if(pos = 1) {
        head = head->link;
        free(curr);
        return head;
    }
    int count = 1;
    while(count < pos - 1){
        curr = curr->link;
        count++;
    }

    NODE* temp = curr->link;
    curr->link = temp->link;
    free(temp);
    return head;
}