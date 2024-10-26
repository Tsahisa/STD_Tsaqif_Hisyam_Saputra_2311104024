#include <iostream>
#include <string>

using namespace std;

// Struktur node untuk mahasiswa
struct Node {
    int NIM;          // Menyimpan NIM mahasiswa
    string nama;      // Menyimpan nama mahasiswa
    Node* next;       // Pointer ke node berikutnya
};

// Struktur Linked List
struct LinkedList {
    Node* head;       // Pointer ke node pertama (head)

    LinkedList() {
        head = nullptr;  // Inisialisasi head dengan null
    }

    // Fungsi untuk membuat node baru dengan data NIM dan Nama
    Node* createNode(int nim, string nama) {
        Node* newNode = new Node();
        newNode->NIM = nim;
        newNode->nama = nama;
        newNode->next = nullptr;
        return newNode;
    }

    // Fungsi untuk menambahkan node di awal list
    void insertFirst(int nim, string nama) {
        Node* newNode = createNode(nim, nama);
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk mencari mahasiswa berdasarkan NIM
    Node* searchByNIM(int nim) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->NIM == nim) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Fungsi untuk menampilkan semua data mahasiswa
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "NIM: " << temp->NIM << ", Nama: " << temp->nama << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    
    // Menambahkan data mahasiswa ke dalam linked list
    list.insertFirst(12345, "Alexander Morrison");
    list.insertFirst(67890, "Olivia Hernandez");
    list.insertFirst(11121, "Daniel Fitzgerald");
    list.insertFirst(54321, "Sophia Whitmore");

    // Menampilkan data mahasiswa yang ada di linked list
    cout << "Daftar Mahasiswa:" << endl;
    list.displayList();

    // Mencari mahasiswa berdasarkan NIM
    int nim;
    cout << "\nMasukkan NIM yang ingin dicari: ";
    cin >> nim;

    Node* result = list.searchByNIM(nim);
    if (result != nullptr) {
        cout << "Mahasiswa ditemukan! Nama: " << result->nama << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    return 0;
}
