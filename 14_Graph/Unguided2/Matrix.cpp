#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;

    vector<vector<int>> adjMatrix(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < jumlahSisi; i++) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;
        adjMatrix[simpul1 - 1][simpul2 - 1] = 1;
        adjMatrix[simpul2 - 1][simpul1 - 1] = 1; 
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
