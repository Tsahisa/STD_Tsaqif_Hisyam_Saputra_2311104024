#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
};

class DoublyLinkedList {
private:
  Node* head;
  Node* tail;

public:
  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void insertFirst(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
      head->prev = newNode;
    }
    head = newNode;

    if (tail == NULL) {
      tail = newNode;
    }
  }

  void insertLast(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
      tail->next = newNode;
    }
    tail = newNode;

    if (head == NULL) {
      head = newNode;
    }
  }

  void printList() {
    Node* current = head;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (current != NULL) {
      cout << current->data;
      if (current->next != NULL) {
        cout << " <-> ";
      }
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  DoublyLinkedList dll;

  dll.insertFirst(40);  // Masukkan elemen pertama
  dll.insertFirst(25);  // Masukkan elemen kedua di awal
  dll.insertLast(60);   // Masukkan elemen ketiga di akhir

  dll.printList();

  return 0;
}
