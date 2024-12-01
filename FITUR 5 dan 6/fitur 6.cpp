#include <iostream>
using namespace std;

int pendapatan = 0;


// Fungsi untuk menampilkan garis horizontal
void garisHorizontal(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}


// Fungsi untuk melihat laporan pendapatan
void laporanPendapatan() {
    garisHorizontal(41);
    cout << "|              LAPORAN PENDAPATAN          |\n";
    garisHorizontal(41);
    cout << "\n++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+ Total Pendapatan: Rp " << pendapatan << "\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++\n";
}

int main() {
                laporanPendapatan();
                system("pause");
                system("cls");
}