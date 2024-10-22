/*Define a structure called Student with the members: Name, Reg_no, marks in
3 tests and average_ marks.
Develop a menu driven program to perform the following by writing separate
function for each operation: a) read information of N students b) display
student’s information c) to calculate the average of best two test marks of
each student.
Note: Allocate memory dynamically and illustrate the use of pointer to an
array of structure. */

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[25];
    int reg_no;
    int m[3];
    float avg;
} Stu;

void read(Stu*, int);
void display(Stu*, int);
float average(int, int, int);

void main() {
    int n; 
    printf("Enter the number of students: \n");
    scanf("%d", &n);

    Stu *students;
    students = (Stu*)malloc(n*sizeof(Stu));

    int choice;

    while(1) {
        printf("\n1->READ\n2->DISPLAY\n3->EXIT\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                read(students, n);
                break;
            case 2:
                display(students, n);
                break;
            case 3:
                exit(0);
            default:
                exit(0);
        }
    }
}

void read(Stu *students, int n) {
    for(int i=0; i<n; i++) {
        printf("\nEnter the student details for student %d: \n", (i+1));

        printf("Enter name: \n");
        scanf("%s", (students+i)->name);

        printf("Enter reg_no: \n");
        scanf("%d", &(students+i)->reg_no);

        printf("Enter 3 marks: \n");
        scanf("%d%d%d", &(students+i)->m[0], &(students+i)->m[1], &(students+i)->m[2]);

        (students+i)->avg = average((students+i)->m[0], (students+i)->m[1], (students+i)->m[2]);
    }
}

void display(Stu *students, int n) {
    for(int i=0; i<n; i++) {
        printf("\nThe student details of student %d: \n", (i+1));
        printf("Name: %s\n", (students+i)->name);
        printf("Reg_no: %d\n", (students+i)->reg_no);
        printf("3 marks: %d %d %d\n", (students+i)->m[0], (students+i)->m[1], (students+i)->m[2]);
        printf("average marks of top 2 scores: %f", (students+i)->avg);
    }
}

float average(int a, int b, int c) {
    int l1, l2;
    if(a <= b && a <= c) {
        return ((b+c) / 2.0);
    }
    else if(b <= a && b <= c) {
        return ((a+c) / 2.0);
    }
    else {
        return ((a+b) / 2.0);
    }
}
 