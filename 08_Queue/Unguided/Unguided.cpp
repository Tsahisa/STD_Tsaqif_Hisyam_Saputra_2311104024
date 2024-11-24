#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int nim;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue() : front(nullptr), back(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, int nim) {
        Node* newNode = new Node{nama, nim, nullptr};

        if (isEmpty() || nim < front->nim) {
            newNode->next = front;
            front = newNode;
            if (back == nullptr) {
                back = newNode;
            }
        } else {
            Node* current = front;
            while (current->next != nullptr && current->next->nim <= nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                back = newNode;
            }
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                back = nullptr;
            }
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* current = front;
            cout << "Data antrian teller:" << endl;
            int position = 1;
            while (current != nullptr) {
                cout << position++ << ". " << current->nama << " (NIM: " << current->nim << ")" << endl;
                current = current->next;
            }
        }
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Antrian telah dikosongkan." << endl;
    }

    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    ~Queue() {
        clearQueue();
    }
};

int main() {
    Queue queue;
    int choice;
    
    do {
        cout << "\nMenu Antrian:\n";
        cout << "1. Tambah Mahasiswa ke Antrian\n";
        cout << "2. Hapus Mahasiswa dari Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Bersihkan Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string nama;
                int nim;
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> ws; 
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                queue.enqueue(nama, nim);
                break;
            }
            case 2: {
                queue.dequeue();
                break;
            }
            case 3: {
                queue.viewQueue();
                cout << "Jumlah antrian = " << queue.countQueue() << endl;
                break;
            }
            case 4: {
                queue.clearQueue();
                break;
            }
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}
