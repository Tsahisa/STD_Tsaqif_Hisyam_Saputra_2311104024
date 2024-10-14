#include <iostream>
using namespace std;

int main() {
    int x = 20;
    int* ptr = &x; // pointer yang menyimpan alamat dari x

    // Menampilkan alamat yang disimpan dalam pointer
    cout << "Alamat dari x: " << ptr << endl;

    // Menampilkan nilai yang ditunjuk oleh pointer
    cout << "Nilai yang ditunjuk oleh ptr: " << *ptr << endl;
    return 0;
}
