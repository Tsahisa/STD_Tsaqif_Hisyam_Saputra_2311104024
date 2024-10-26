#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke akhir list
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menampilkan elemen-elemen list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Prosedur Bubble Sort untuk mengurutkan elemen dalam linked list
void bubbleSort(Node* head) {
    if (head == nullptr) return; // Jika list kosong, tidak ada yang diurutkan

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;  // Untuk menandai batas bagian yang sudah terurut

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Tukar data
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;  // Update batas bagian yang sudah terurut
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    int elements[5];

    // Meminta input 5 elemen dari pengguna
    cout << "Masukkan 5 elemen integer ke dalam list:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> elements[i];
        insert(head, elements[i]);
    }

    // Menampilkan list sebelum sorting
    cout << "List sebelum diurutkan: ";
    displayList(head);

    // Mengurutkan list menggunakan bubble sort
    bubbleSort(head);

    // Menampilkan list setelah sorting
    cout << "List setelah diurutkan: ";
    displayList(head);

    return 0;
}
