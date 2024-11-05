#ifndef STACK_H
#define STACK_H

const int MAX = 20;

typedef int Infotype;
typedef struct {
    Infotype data[MAX];
    int top;
} Stack;

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, Infotype x);
void pop(Stack &S, Infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, Infotype x);
void getInputStream(Stack &S);

#endif
