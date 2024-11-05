#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Welcome to the Stack Program!" << endl;

    Stack S;
    createStack(S);

    push(S, 9);
    push(S, 8);
    push(S, 4);
    push(S, 3);
    push(S, 2);
    cout << "Stack setelah push:" << endl;
    printInfo(S);

    balikStack(S);
    cout << "Stack setelah dibalik:" << endl;
    printInfo(S);

    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 8);
    pushAscending(S, 4);
    pushAscending(S, 9);
    pushAscending(S, 2);
    cout << "Stack setelah push ascending:" << endl;
    printInfo(S);

    createStack(S);
    getInputStream(S);
    cout << "Stack setelah input stream:" << endl;
    printInfo(S);

    return 0;
}
