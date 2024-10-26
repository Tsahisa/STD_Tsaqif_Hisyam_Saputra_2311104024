#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke dalam list secara urut
void insertSorted(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // Jika list kosong atau nilai elemen yang baru lebih kecil dari head, masukkan di depan
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        // Cari posisi yang sesuai untuk memasukkan elemen baru
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
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

int main() {
    Node* head = nullptr;
    int elements[4];

    // Meminta input 4 elemen dari pengguna untuk membuat list terurut
    cout << "Masukkan 4 elemen integer yang sudah terurut ke dalam list:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> elements[i];
        insertSorted(head, elements[i]);
    }

    // Menampilkan list sebelum menambahkan elemen baru
    cout << "List sebelum elemen baru dimasukkan: ";
    displayList(head);

    // Meminta elemen baru yang akan dimasukkan secara terurut
    int newValue;
    cout << "Masukkan elemen baru yang ingin dimasukkan: ";
    cin >> newValue;

    // Menambahkan elemen baru ke dalam list yang sudah terurut
    insertSorted(head, newValue);

    // Menampilkan list setelah elemen baru dimasukkan
    cout << "List setelah elemen baru dimasukkan: ";
    displayList(head);

    return 0;
}
