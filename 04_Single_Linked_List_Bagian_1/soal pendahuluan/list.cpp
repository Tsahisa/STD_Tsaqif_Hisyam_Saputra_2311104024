#include "list.h"

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L) {
    address P = first(L);
    while (P != NULL) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}

// Implementasi fungsi tambahan untuk "Have Fun" section
void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        insertFirst(L, P);
    } else {
        address Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteLast(List &L) {
    if (first(L) != NULL) {
        address P = first(L);
        address Q = NULL;
        while (next(P) != NULL) {
            Q = P;
            P = next(P);
        }
        if (Q == NULL) {
            first(L) = NULL;
        } else {
            next(Q) = NULL;
        }
        delete P;
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != NULL) {
        address P = next(Prec);
        if (P != NULL) {
            next(Prec) = next(P);
            delete P;
        }
    }
}

address searchInfo(List L, infotype x) {
    address P = first(L);
    while (P != NULL && info(P) != x) {
        P = next(P);
    }
    return P;
}