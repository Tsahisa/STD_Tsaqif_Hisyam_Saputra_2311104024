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

    // Fungsi untuk menghapus node dengan nilai tertentu
    void deleteNode(int value) {
        // Jika list kosong
        if (head == nullptr) {
            cout << "List kosong, tidak ada yang dapat dihapus." << endl;
            return;
        }

        // Jika node pertama (head) yang ingin dihapus
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // Head menunjuk ke node berikutnya
            delete temp;        // Hapus node lama
            return;
        }

        // Mencari node yang akan dihapus
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        // Jika node ditemukan
        if (temp->next != nullptr) {
            Node* delNode = temp->next;
            temp->next = delNode->next;  // Hubungkan node sebelum dengan node sesudahnya
            delete delNode;              // Hapus node
        } else {
            cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
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
    list.insertFront(15);  
    list.insertBack(25);   
    list.insertFront(10);   

    // Cetak linked list sebelum penghapusan
    cout << "Isi Linked List sebelum penghapusan: ";
    list.printList();  

    // Menghapus node dengan nilai 10
    list.deleteNode(10);

    // Cetak linked list setelah penghapusan
    cout << "Isi Linked List setelah penghapusan: ";
    list.printList();  

    return 0;
}
