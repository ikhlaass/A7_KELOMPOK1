#include <iostream>
using namespace std;

void garisHorizontal(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}

void tampilkanMenu() {
    garisHorizontal(41);
    cout << "|          Aplikasi Parkir Mobil         |\n";
    garisHorizontal(41);
    cout << "| 1. Masukkan Mobil                      |\n";
    cout << "| 2. Keluarkan Mobil                     |\n";
    cout << "| 3. Lihat Slot Parkir                   |\n";
    cout << "| 4. Lihat Riwayat Parkir                |\n";
    cout << "| 5. Lihat Antrean                       |\n";
    cout << "| 6. Laporan Pendapatan                  |\n";
    cout << "| 0. Keluar                              |\n";
    garisHorizontal(40);
    cout << "Pilihan: ";
}


int main() {
    tampilkanMenu();
}