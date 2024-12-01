#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Konstanta
const int MAX_SLOT = 1; // Kapasitas maksimum slot parkir

// Struktur data parkir
string slotParkir[MAX_SLOT];
string waktuParkir[MAX_SLOT];
int jumlahSlotTerisi = 0;

// Fungsi untuk menampilkan garis horizontal
void garisHorizontal(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}

// Fungsi untuk melihat slot parkir
void lihatSlotParkir() {
    garisHorizontal(41);
    cout << "|           SLOT PARKIR SAAT INI           |\n";
    garisHorizontal(41);
    if (jumlahSlotTerisi == 0) {
        cout << "Slot parkir kosong.\n";
    } else {
        cout << "\n++++++++++++++++++++++++++++++++++++++++++\n";
        for (int i = 0; i < jumlahSlotTerisi; i++) {
            cout << "+ Slot    : " << i + 1 << "\n";
            cout << "+ Plat    : " << slotParkir[i] << "\n";
            cout << "+ Masuk   : " << waktuParkir[i] << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
        }
    }
    cout << "\n";
}

int main() {
    lihatSlotParkir();
    system("read");
    system("clear");
}
