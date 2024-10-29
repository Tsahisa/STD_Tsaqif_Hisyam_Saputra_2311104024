#include <iostream>
using namespace std;

// Struktur Node untuk Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi untuk menambahkan elemen di akhir list
void insertLast(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk menampilkan elemen dari depan ke belakang
void displayForward(Node* head) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    cout << "Elemen dari depan ke belakang: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi untuk menampilkan elemen dari belakang ke depan
void displayBackward(Node* head) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    
    // Bergerak ke elemen terakhir
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "Elemen dari belakang ke depan: ";
    // Menampilkan dari elemen terakhir ke awal
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Menambahkan 4 elemen ke dalam list
    insertLast(head, 10); // Elemen pertama
    insertLast(head, 20); // Elemen kedua
    insertLast(head, 30); // Elemen ketiga
    insertLast(head, 40); // Elemen keempat

    // Menampilkan elemen dari depan ke belakang
    displayForward(head);

    // Menampilkan elemen dari belakang ke depan
    displayBackward(head);

    return 0;
}
