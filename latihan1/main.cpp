/*#include <iostream>

using namespace std;

int main(){
    float bil1, bil2;
    cout << "Masukkan bilangan pertama: ";
    cin >> bil1;

    cout << "Masukkan bilangan kedua: ";
    cin >> bil2;

    cout << "Hasil penjuumlahan: " << bil1 + bil2 << endl;
    cout << "Hasil pengurangan: " << bil1 - bil2 << endl;
    cout << "Hasil perkalian: " << bil1 * bil2 << endl;
    cout << "Hasil pembagian: " << bil1 / bil2 << endl;

    return 0;
}*/

/*#include <iostream>
using namespace std;

string angkaKeTulisan(int angka) {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
    string puluhan[] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka == 0)
        return "nol";
    else if (angka <= 11)
        return satuan[angka];
    else if (angka < 20)
        return satuan[angka - 10] + " belas";
    else if (angka <= 99)
        return puluhan[angka / 10] + (angka % 10 != 0 ? " " + satuan[angka % 10] : "");
    else if (angka == 100)
        return "seratus";

    return "";
}

int main() {
    int angka;


    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka yang dimasukkan harus antara 0 hingga 100." << endl;
    } else {

        cout << "Angka dalam tulisan: " << angkaKeTulisan(angka) << endl;
    }

    return 0;
}*/

/*#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        if (i != 1) {
            cout << " * ";
        }
        for (int j = 2; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}*/
