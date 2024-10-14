#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas)+(0.3 * tugas);
}

int main() {
    const int MAX_MAHASISWA = 10;
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlahMahasiswa;

    // Validasi jumlah mahasiswa
    if (jumlahMahasiswa > MAX_MAHASISWA || jumlahMahasiswa <= 0) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 1;
    }

    // Input data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;

        // Hitung nilai akhir
        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    // Tampilkan data mahasiswa
    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << endl;
        cout << "Nama        : " << mahasiswa[i].nama << endl;
        cout << "NIM         : " << mahasiswa[i].nim << endl;
        cout << "Nilai UTS   : " << mahasiswa[i].uts << endl;
        cout << "Nilai UAS   : " << mahasiswa[i].uas << endl;
        cout << "Nilai Tugas : " << mahasiswa[i].tugas << endl;
        cout << "Nilai Akhir : " << mahasiswa[i].nilaiAkhir << endl;
    }

    return 0;
}
