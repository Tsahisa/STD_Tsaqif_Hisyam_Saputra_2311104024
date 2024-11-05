#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, Infotype x) {
    if (!isFull(S)) {
        S.data[++S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &S, Infotype &x) {
    if (!isEmpty(S)) {
        x = S.data[S.top--];
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    Infotype x;
    while (!isEmpty(S)) {
        pop(S, x);
        push(temp, x);
    }
    S = temp;
}

void pushAscending(Stack &S, Infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    Stack temp;
    createStack(temp);
    Infotype val;
    while (!isEmpty(S) && S.data[S.top] > x) {
        pop(S, val);
        push(temp, val);
    }
    push(S, x);
    while (!isEmpty(temp)) {
        pop(temp, val);
        push(S, val);
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan angka (akhiri dengan Enter): ";
    while (cin.get(ch) && ch != '\n') {
        if (isdigit(ch)) {
            int value = ch - '0';
            push(S, value);
        }
    }
}
