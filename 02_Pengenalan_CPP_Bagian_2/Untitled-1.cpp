// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cout << "Masukkan jumlah elemen array: ";
//     cin >> n;

//     vector<int> arr(n);
//     vector<int> genap;
//     vector<int> ganjil;

//     cout << "Masukkan elemen array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//         if (arr[i] % 2 == 0) {
//             genap.push_back(arr[i]); 
//         } else {
//             ganjil.push_back(arr[i]); 
//         }
//     }

//     // Menampilkan array awal
//     cout << "Data Array : ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     cout << "Nomor Genap : ";
//     for (int i = 0; i < genap.size(); i++) {
//         cout << genap[i];
//         if (i < genap.size() - 1) cout << ", "; 
//     }
//     cout << endl;

//     cout << "Nomor Ganjil : ";
//     for (int i = 0; i < ganjil.size(); i++) {
//         cout << ganjil[i];
//         if (i < ganjil.size() - 1) cout << ", ";
//     }
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int x, y, z;

//     cout << "Masukkan ukuran dimensi pertama (x): ";
//     cin >> x;
//     cout << "Masukkan ukuran dimensi kedua (y): ";
//     cin >> y;
//     cout << "Masukkan ukuran dimensi ketiga (z): ";
//     cin >> z;

//     int arr[x][y][z];

//     cout << "Masukkan elemen array:" << endl;
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             for (int k = 0; k < z; k++) {
//                 cout << "arr[" << i << "][" << j << "][" << k << "] = ";
//                 cin >> arr[i][j][k];
//             }
//         }
//     }

//     cout << "Array 3D yang diinputkan:" << endl;
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             for (int k = 0; k < z; k++) {
//                 cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
//             }
//         }
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int n, pilihan;
//     cout << "Masukkan jumlah elemen array: ";
//     cin >> n;

//     int arr[n], maks, min;
//     double total = 0;

//     cout << "Masukkan elemen array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//         total += arr[i];
//         if (i == 0) {
//             maks = min = arr[i];
//         } else {
//             if (arr[i] > maks) maks = arr[i];
//             if (arr[i] < min) min = arr[i];
//         }
//     }

//     do {
//         cout << "\n1. Maksimum\n2. Minimum\n3. Rata-rata\n4. Keluar\nPilihan: ";
//         cin >> pilihan;

//         if (pilihan == 1) cout << "Maksimum: " << maks << endl;
//         else if (pilihan == 2) cout << "Minimum: " << min << endl;
//         else if (pilihan == 3) cout << "Rata-rata: " << total / n << endl;

//     } while (pilihan != 4);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int kendaraan(int kapasitas_kendaraan, int jumlah_penumpang) {
//     int jumlah;
//     jumlah = jumlah_penumpang / kapasitas_kendaraan;
//     if (jumlah_penumpang % kapasitas_kendaraan > 0) {
//         jumlah++;
//     }
//     return jumlah;
// }

// int main() {
//     int kap_kendaraan, jum_penumpang, banyak_kendaraan;
//     cout << "Masukkan kapasitas kendaraan: ";
//     cin >> kap_kendaraan;
//     cout << "Masukkan jumlah penumpang: ";
//     cin >> jum_penumpang;
    
//     banyak_kendaraan = kendaraan(kap_kendaraan, jum_penumpang);
//     cout << "Banyak kendaraan yang disewa = " << banyak_kendaraan << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// void tukar(int *a, int *b) {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main() {
//     int bil1, bil2;
//     cout << "Masukkan bilangan pertama: ";
//     cin >> bil1;
//     cout << "Masukkan bilangan kedua: ";
//     cin >> bil2;

//     cout << "Sebelum pertukaran:\n";
//     cout << "Bil 1: " << bil1 << " bil 2: " << bil2 << endl;

//     tukar(&bil1, &bil2);

//     cout << "Setelah pertukaran:\n";
//     cout << "Bil 1: " << bil1 << " bil 2: " << bil2 << endl;

//     return 0;
// }

// #include <iostream>  

// using namespace std;  

// int main(){  
//     int bil[10];  
//     bil[0] = 1;  
//     bil[1] = 4;  
//     bil[2] = 5;  
//     cout << bil[0] << endl;  
//     cout << bil[1] << endl;  
//     cout << bil[2] << endl;  
//     cout << bil[0] + bil[1] + bil[2] << endl;  
//     return 0;  
// }