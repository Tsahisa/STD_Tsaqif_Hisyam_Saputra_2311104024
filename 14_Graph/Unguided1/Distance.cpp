#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int jumlahSimpul;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Silakan masukan nama simpul\nSimpul " << i + 1 << " : ";
        cin >> namaSimpul[i];
    }

    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Silakan masukkan bobot antar simpul\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            if (i == j) {
                cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = 0\n";
                bobot[i][j] = 0; 
            } else {
                cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = ";
                cin >> bobot[i][j];
            }
        }
    }

    cout << endl;
    cout << setw(10) << "" << setw(10) << namaSimpul[0] << setw(10) << namaSimpul[1] << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << setw(10) << namaSimpul[i];
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << setw(10) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}