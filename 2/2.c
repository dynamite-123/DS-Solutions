/*Define a structure called Time containing 3 integer members (hour, minute,
second). Develop a menu driven program to perform the following by writing
separate function for each operation.
a) Read (T): To read time
b) Display (T):To display time
c) update(T):To Update time
d) Add (T1, T2) : Add two times.
Update function increments the time by one second and returns the new time
(if the increment results in 60 seconds, then the second member is set to zero
and minute member is incremented by one. If the result is 60 minutes, the
minute member is set to zero and the hour member is incremented by one.
Finally, when the hour becomes 24, Time should be reset to zero. While
adding two time variable, normalize the resultant time value as in the case of
update function.
Note: Illustrate the use of pointer to pass time variable to different functions.*/

#include <stdio.h>
#include <stdlib.h>

struct Time {
    int hour, minute, second;
};

void Read(struct Time *t);
void Display(struct Time *t);
void Update(struct Time *t);
void Add(struct Time *t1, struct Time *t2);

void main() {
    struct Time *t1, *t2;
    int choice, mark = 0;
    t1 = (struct Time *)malloc(sizeof(struct Time));
    t2 = (struct Time *)malloc(sizeof(struct Time));
    if ((t1 == NULL) || (t1 == NULL)) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    options:{
        printf("\n1->Read\n2->Display\n3->Update\n4->Add\n5->exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Read(t1);
            mark++;
            break;
        case 2:
            if(mark == 0){
                printf("Haven't read any time");
                break;
            }
            Display(t1);
            break;
        case 3:
            if(mark = 0){
                printf("Haven't read any time");
                break;
            }
            Update(t1);
            break;
        case 4:
            Read(t1);
            Read(t2);
            Add(t1, t2);
            break;
        case 5:
            exit(0);
        }
    }
    goto options;
   
    free(t1);
    free(t2);
}

void Read(struct Time *t) {
    printf("ENTER TIME:\n");
    printf("hour: ");
    scanf("%d", &t->hour);

    printf("minute: ");
    scanf("%d", &t->minute);

    printf("hour: ");
    scanf("%d", &t->second);

    if (t->hour < 0 || t->hour > 24) {
        printf("Invalid time");
        exit(0);
    }
    if (t->minute < 0 || t->minute > 60) {
        printf("Invalid time");
        exit(0);
    }
    if (t->second < 0 || t->second > 60) {
        printf("Invalid time");
        exit(0);
    }
}

void Display(struct Time *t) {
    printf("TIME:\nhour: %d\nminute: %d\nsecond: %d\n", t->hour, t->minute, t->second);
}

void Update(struct Time *t) {
    t->second++;
    if (t->second == 60) {
        t->minute++;
    }
    if (t->minute == 60) {
        t->hour++;
    }
    if (t->hour == 24) {
        t->second = 0;
        t->minute = 0;
        t->hour = 0;
    }
    printf("UPDATED TIME:\nhour: %d\nminute: %d\nsecond: %d\n", t->hour, t->minute, t->second);
}

void Add(struct Time *t1, struct Time *t2) {
    struct Time t3;
    int xmin = (t1->second + t2->second) / 60;
    t3.second = (t1->second + t2->second) % 60;

    int xhour = (t1->minute + t2->minute + xmin) / 60;
    t3.minute = (t1->minute + t2->minute + xmin) % 60;

    t3.hour = (t1->hour + t2->hour + xhour) % 24;

    printf("ADDED TIME:\nhour: %d\nminute: %d\nsecond: %d\n", t3.hour, t3.minute, t3.second);
}
