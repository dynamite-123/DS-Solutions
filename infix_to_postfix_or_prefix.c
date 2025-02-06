#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct {
    char arr[MAX];
    int top;
} Stack;

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

char peek(Stack *s) {
    return s->arr[s->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void infix_to_postfix(char *infix, char *postfix) {
    Stack s;
    s.top = -1;

    int i, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isOperator(infix[i])) {
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])){
                postfix[j++] = pop(&s); 
            }
            push(&s, infix[i]);
        }

        else if(infix[i] == '('){
            push(&s, '(');
        }

        else if(infix[i] == ')'){
            while(!isEmpty(&s) && peek(&s) != '('){
                postfix[j++] = pop(&s);
            }
        pop(&s);
        }

        else{
            postfix[j++] = infix[i];
        }

    }
    while(!isEmpty(&s)){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

void reverse(char *arr) {
    int i = 0;
    int j = 0;
    while(arr[j] != '\0'){
        j++;
    }
    j--;
    while(i <= j){
        char temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    } 
    for(int k = 0; arr[k] != '\0'; k++){
        if(arr[k] == '(') arr[k] = ')';
        else if(arr[k] == ')') arr[k] = '(';
    }
} 
void infix_to_prefix(char *infix, char *prefix) {
    reverse(infix);
    infix_to_postfix(infix, prefix);
    reverse(prefix);
    reverse(infix);
}

void main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infix_to_postfix(infix, postfix); 
    infix_to_prefix(infix, prefix);
    
    printf("Postfix expression: %s\n", postfix);
    printf("Prefix expression: %s\n", prefix);
    
}