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

// Fungsi untuk menghapus elemen pertama dalam list
void deleteFirst(Node*& head) {
    if (head == nullptr) {
        cout << "List kosong, tidak ada elemen untuk dihapus." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

// Fungsi untuk menghapus elemen terakhir dalam list
void deleteLast(Node*& head) {
    if (head == nullptr) {
        cout << "List kosong, tidak ada elemen untuk dihapus." << endl;
        return;
    }

    if (head->next == nullptr) {
        // Jika hanya ada satu elemen
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }
}

// Fungsi untuk menampilkan seluruh elemen dalam list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Input elemen-elemen sesuai instruksi
    insertLast(head, 30); // Elemen pertama
    insertLast(head, 45); // Elemen kedua
    insertLast(head, 60); // Elemen ketiga

    cout << "List sebelum penghapusan:" << endl;
    displayList(head);

    // Menghapus elemen pertama dan terakhir
    deleteFirst(head);
    deleteLast(head);

    cout << "List setelah penghapusan:" << endl;
    displayList(head);

    return 0;
}
