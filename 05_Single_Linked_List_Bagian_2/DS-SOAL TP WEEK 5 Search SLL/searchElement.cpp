#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the list
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

// Function to search for an element in the list
void searchElement(Node* head, int key) {
    Node* current = head;
    int position = 1;
    bool found = false;

    while (current != nullptr) {
        if (current->data == key) {
            found = true;
            cout << "Elemen ditemukan pada alamat: " << current << " di posisi ke-" << position << endl;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Elemen tidak ditemukan dalam list." << endl;
    }
}

int main() {
    Node* head = nullptr;
    int elements[6];

    // Input 6 elements from user
    cout << "Masukkan 6 elemen integer ke dalam list:" << endl;
    for (int i = 0; i < 6; i++) {
        cin >> elements[i];
        insert(head, elements[i]);
    }

    int searchValue;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> searchValue;

    // Search for the element
    searchElement(head, searchValue);

    return 0;
}
