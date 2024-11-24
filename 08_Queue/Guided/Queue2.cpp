#include <iostream>  
using namespace std;  

// Definisi Struktur Node  
struct Node {  
    int data;  
    Node* next;  
};  

// Fungsi Membuat Elemen Baru  
Node* newElement(int data) {  
    Node* newNode = new Node();  
    newNode->data = data;  
    newNode->next = nullptr;  
    return newNode;  
}  

// Fungsi Membuat List Baru (Kosong)  
Node* createNewList() {  
    return nullptr; // List baru dimulai dari NULL (kosong)  
}  

// Fungsi Mengecek Apakah List Kosong  
bool isEmpty(Node* head) {  
    return head == nullptr;  
}  

// Fungsi Utama  
int main() {  
    Node* head = createNewList(); // Membuat list baru  
    int input;  

    // Proses Input  
    cout << "Masukkan satu buah bilangan bulat (0 untuk keluar): ";  
    while (cin >> input && input != 0) {  
        Node* newNode = newElement(input); // Membuat elemen baru  

        // Menambahkan elemen baru ke dalam list  
        if (isEmpty(head)) {  
            head = newNode; // Jika list kosong, head menjadi node baru  
            cout << "1" << endl; // List sekarang tidak kosong  
        } else {  
            Node* temp = head;  
            while (temp->next != nullptr) { // Mencari akhir list  
                temp = temp->next;  
            }  
            temp->next = newNode; // Menambahkan node baru di akhir list  
            cout << "0" << endl; // List tidak kosong  
        }  
        
        // Menampilkan data dari elemen yang baru dibuat  
        cout << newNode->data << endl;   
        cout << "Masukkan satu buah bilangan bulat (0 untuk keluar): ";  
    }  

    // Menampilkan semua elemen dalam list sebelum keluar  
    cout << "Data dari list yang dibuat:\n";  
    Node* temp = head;  
    while (temp != nullptr) {  
        cout << temp->data << " ";  
        temp = temp->next;  
    }  
    cout << endl; // Baris baru setelah daftar elemen  

    // Membersihkan memori  
    while (head != nullptr) {  
        Node* temp = head;  
        head = head->next;  
        delete temp; // Menghapus node  
    }  

    return 0;  
}   