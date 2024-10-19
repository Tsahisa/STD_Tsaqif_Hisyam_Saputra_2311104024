#include "list.h"

int main() {
    List L;
    createList(L);

    cout << "Masukkan NIM perdigit" << endl;
    for (int i = 1; i <= 10; i++) {
        int digit;
        cout << "Digit " << i << " : ";
        cin >> digit;
        address P = allocate(digit);
        insertLast(L, P);
    }
}
    