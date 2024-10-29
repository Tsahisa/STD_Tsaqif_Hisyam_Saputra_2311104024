#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk menyimpan data buku
struct Node {
  int IDBuku;
  string JudulBuku;
  string PenulisBuku;
  Node* next;
  Node* prev;
};

// Fungsi untuk membuat node baru
Node* newNode(int IDBuku, string JudulBuku, string PenulisBuku) {
  Node* node = new Node;
  node->IDBuku = IDBuku;
  node->JudulBuku = JudulBuku;
  node->PenulisBuku = PenulisBuku;
  node->next = nullptr;
  node->prev = nullptr;
  return node;
}

// Fungsi untuk menambahkan buku di akhir linked list
void append(Node** head, Node** tail, int IDBuku, string JudulBuku, string PenulisBuku) {
  Node* new_node = newNode(IDBuku, JudulBuku, PenulisBuku);

  // Jika list kosong
  if (*head == nullptr) {
    *head = new_node;
    *tail = new_node;
    return;
  }

  // Tambahkan node baru di akhir list
  (*tail)->next = new_node;
  new_node->prev = *tail;
  *tail = new_node;
}

// Fungsi untuk menampilkan semua buku dari awal ke akhir
void printList(Node* node) {
  while (node != nullptr) {
    cout << "ID Buku: " << node->IDBuku << endl;
    cout << "Judul Buku: " << node->JudulBuku << endl;
    cout << "Penulis Buku: " << node->PenulisBuku << endl;
    cout << endl;
    node = node->next;
  }
}

// Fungsi untuk menampilkan semua buku dari akhir ke awal
void printReverseList(Node* node) {
  while (node != nullptr) {
    cout << "ID Buku: " << node->IDBuku << endl;
    cout << "Judul Buku: " << node->JudulBuku << endl;
    cout << "Penulis Buku: " << node->PenulisBuku << endl;
    cout << endl;
    node = node->prev;
  }
}

int main() {
  Node* head = nullptr;
  Node* tail = nullptr;

  // Menambahkan beberapa buku ke dalam linked list
  append(&head, &tail, 1, "Art of War", "Sun Tzu");
  append(&head, &tail, 2, "Shrek", "William Steig");
  append(&head, &tail, 3, "I Have No Mouth, and I Must Scream", "Harlan Ellison");

  cout << "Daftar Buku dari awal ke akhir:" << endl;
  printList(head);

  cout << "Daftar Buku dari akhir ke awal:" << endl;
  printReverseList(tail);

  return 0;
}
