#include <iostream>
#include <cmath>
using namespace std;

// Definisi ADT untuk Kerucut
struct Kerucut {
    double radius;
    double tinggi;
};

// Fungsi untuk menghitung luas permukaan kerucut
double hitungLuasPermukaan(const Kerucut& k) {
    double s = sqrt((k.radius * k.radius) + (k.tinggi * k.tinggi)); // garis pelukis
    return M_PI * k.radius * (k.radius + s);
}

// Fungsi untuk menghitung volume kerucut
double hitungVolume(const Kerucut& k) {
    return (1.0 / 3.0) * M_PI * k.radius * k.radius * k.tinggi;
}

int main() {
    Kerucut k;

    // Input data kerucut
    cout << "Masukkan radius kerucut: ";
    cin >> k.radius;
    cout << "Masukkan tinggi kerucut: ";
    cin >> k.tinggi;

    // Menghitung dan menampilkan luas permukaan dan volume
    double luasPermukaan = hitungLuasPermukaan(k);
    double volume = hitungVolume(k);

    cout << "Luas Permukaan Kerucut: " << luasPermukaan << endl;
    cout << "Volume Kerucut: " << volume << endl;

    return 0;
}
