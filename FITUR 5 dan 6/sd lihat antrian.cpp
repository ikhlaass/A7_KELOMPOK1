#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Konstanta
const int MAX_SLOT = 1; // Kapasitas maksimum slot parkir
const int MAX_QUEUE = 1; // Kapasitas maksimum antrean


// Struktur data antrean
string waktuAntrean[MAX_SLOT];
string antreanMobil[MAX_QUEUE];
int frontAntrean = 0, rearAntrean = -1, jumlahAntrean = 0;

// Fungsi untuk menampilkan garis horizontal
void garisHorizontal(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}

// Fungsi untuk melihat antrean
void lihatAntrean() {
    garisHorizontal(41);
    cout << "|              ANTREAN SAAT INI            |\n";
    garisHorizontal(41);
    if (jumlahAntrean == 0) {
        cout << "Antrean kosong.\n";
    } else {
        cout << "\n++++++++++++++++++++++++++++++++++++++++++\n";
        for (int i = frontAntrean; i <= rearAntrean; i++) {
            cout << "+ Antrean Ke: " << i + 1 - frontAntrean << "\n";
            cout << "+ Plat       : " << antreanMobil[i] << "\n";
            cout << "+ Masuk      : " << waktuAntrean[i] << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
        }
    }
}

int main() {
            
                lihatAntrean();
                system("pause");
                system("cls");
               
}