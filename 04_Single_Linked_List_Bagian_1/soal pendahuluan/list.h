#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address allocate(infotype x);
void insertFirst(List &L, address P);
void printInfo(List L);

// Tambahan untuk "Have Fun" section
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
address searchInfo(List L, infotype x);

#endif // LIST_H_INCLUDED