#include <iostream>
using namespace std;

// Deklarasi ukuran array
const int SIZE = 3;

// Fungsi untuk menampilkan isi array 2D
void tampilArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menukarkan nilai pada posisi tertentu antara dua array 2D
void tukarArray(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int row, int col) {
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

// Fungsi untuk menukarkan nilai yang ditunjuk oleh dua pointer integer
void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Deklarasi dua array 2D berukuran 3x3
    int array1[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[SIZE][SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    // Deklarasi dua pointer integer
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;

    // Tampilkan array sebelum ditukar
    cout << "Array 1 sebelum ditukar:\n";
    tampilArray(array1);
    cout << "\nArray 2 sebelum ditukar:\n";
    tampilArray(array2);

    // Tukar nilai di posisi tertentu pada kedua array
    tukarArray(array1, array2, 1, 1); // Contoh: menukar elemen pada posisi (1,1)

    // Tampilkan array setelah ditukar
    cout << "\nArray 1 setelah ditukar:\n";
    tampilArray(array1);
    cout << "\nArray 2 setelah ditukar:\n";
    tampilArray(array2);

    // Tampilkan nilai yang ditunjuk oleh pointer sebelum ditukar
    cout << "\nNilai sebelum ditukar:\n";
    cout << "a = " << a << ", b = " << b << endl;

    // Tukar nilai dari variabel yang ditunjuk oleh pointer
    tukarPointer(ptr1, ptr2);

    // Tampilkan nilai yang ditunjuk oleh pointer setelah ditukar
    cout << "\nNilai setelah ditukar:\n";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
