#include <iostream>
using namespace std;

// Struktur node untuk single linked list
struct Node {
    int data;
    Node* next;
};

// Struktur untuk linked list
struct LinkedList {
    Node* head;  // Pointer ke node pertama (head)

    // Konstruktor untuk membuat linked list kosong
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambah node di depan
    void insertFront(int value) {
        Node* newNode = new Node();  // Alokasi memori untuk node baru
        newNode->data = value;       // Mengisi data node baru
        newNode->next = head;        // Menghubungkan node baru ke list yang sudah ada
        head = newNode;              // Menjadikan node baru sebagai head
    }

    // Fungsi untuk menambah node di belakang
    void insertBack(int value) {
        Node* newNode = new Node();  // Alokasi memori untuk node baru
        newNode->data = value;       // Mengisi data node baru
        newNode->next = nullptr;     // Node baru akan menjadi node terakhir, jadi next-nya null

        // Jika linked list masih kosong
        if (head == nullptr) {
            head = newNode;          // Menjadikan node baru sebagai head
        } else {
            Node* temp = head;
            // Mencari node terakhir
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;    // Menambahkan node baru di belakang node terakhir
        }
    }

    // Fungsi untuk mencetak seluruh isi linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";  // Memisahkan elemen dengan "->"
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

// Program utama
int main() {
    LinkedList list;  // Membuat linked list kosong

    // Input seperti pada soal
    list.insertFront(20);  
    list.insertBack(30);   
    list.insertFront(15);   

    // Cetak linked list
    cout << "Isi Linked List: ";
    list.printList();  

    return 0;
}
