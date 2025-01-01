#include <iostream>
#include <limits>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root = nullptr;

void init() {
    root = nullptr;
}

bool isEmpty() {
    return root == nullptr;
}

Pohon* buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, nullptr, nullptr, nullptr};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
        return root;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
        return nullptr;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return nullptr;
    }

    if (node->left != nullptr) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return nullptr;
    }

    Pohon* baru = new Pohon{data, nullptr, nullptr, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return nullptr;
    }

    if (node->right != nullptr) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return nullptr;
    }

    Pohon* baru = new Pohon{data, nullptr, nullptr, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }

    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }

    cout << "\nData Node: " << node->data << endl;
    if (node->parent) {
    cout << "Parent: " << node->parent->data << endl;
    } else {
    cout << "Parent: Tidak ada parent" << endl;
    }

    if (node->left) cout << "Left Child: " << node->left->data << endl;
    else cout << "Left Child: (None)" << endl;

    if (node->right) cout << "Right Child: " << node->right->data << endl;
    else cout << "Right Child: (None)" << endl;
}

void showDescendants(Pohon *node) {
    if (!node) return;
    if (node->left) {
        cout << node->left->data << " ";
        showDescendants(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        showDescendants(node->right);
    }
}

bool is_valid_bst(Pohon *node, char min_val, char max_val) {
    if (!node) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) && is_valid_bst(node->right, node->data, max_val);
}

int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

int main() {
    int choice;
    do {
        cout << "\nMenu Tree:\n";
        cout << "1. Buat Root Node\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Show Descendants\n";
        cout << "8. Check if Tree is Valid BST\n";
        cout << "9. Count Leaf Nodes\n";
        cout << "10. Exit\n";
        cout << "Pilihan: ";
        cin >> choice;

        char data, parent_data;
        Pohon *node = nullptr;

        switch (choice) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                node = buatNode(data);
                break;
            case 2:
                cout << "Masukkan data parent: ";
                cin >> parent_data;
                node = root; 
                while (node && node->data != parent_data) {
                    node = (node->left && node->left->data == parent_data) ? node->left : node->right;
                }
                if (node) {
                    cout << "Masukkan data node kiri: ";
                    cin >> data;
                    insertLeft(data, node);
                } else {
                    cout << "Parent tidak ditemukan.\n";
                }
                break;
            case 3:
                cout << "Masukkan data parent: ";
                cin >> parent_data;
                node = root; 
                while (node && node->data != parent_data) {
                    node = (node->left && node->left->data == parent_data) ? node->left : node->right;
                }
                if (node) {
                    cout << "Masukkan data node kanan: ";
                    cin >> data;
                    insertRight(data, node);
                } else {
                    cout << "Parent tidak ditemukan.\n";
                }
                break;
            case 4:
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> parent_data;
                node = root; 
                while (node && node->data != parent_data) {
                    node = (node->left && node->left->data == parent_data) ? node->left : node->right;
                }
                if (node) {
                    cout << "Masukkan data baru: ";
                    cin >> data;
                    update(data, node);
                } else {
                    cout << "Node tidak ditemukan.\n";
                }
                break;
            case 5:
                retrieve(root);
                break;
            case 6:
                cout << "Masukkan data node yang ingin dicari: ";
                cin >> data;
                node = root;
                while (node && node->data != data) {
                    node = (node->left && node->left->data == data) ? node->left : node->right;
                }
                if (node) {
                    find(node);
                } else {
                    cout << "Node tidak ditemukan.\n";
                }
                break;
            case 7:
                cout << "Masukkan data node yang ingin ditampilkan descendantnya: ";
                cin >> data;
                node = root;
                while (node && node->data != data) {
                    node = (node->left && node->left->data == data) ? node->left : node->right;
                }
                if (node) {
                    cout << "Descendants of " << data << ": ";
                    showDescendants(node);
                    cout << endl;
                } else {
                    cout << "Node tidak ditemukan.\n";
                }
                break;
            case 8:
                cout << "Tree is " << (is_valid_bst(root, CHAR_MIN, CHAR_MAX) ? "a valid BST" : "not a valid BST") << endl;
                break;
            case 9:
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
                break;
            case 10:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (choice != 10);

    return 0;
}
