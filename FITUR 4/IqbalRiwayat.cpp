#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Konstanta
const int MAX_SLOT = 1; // Kapasitas maksimum slot parkir
const int MAX_QUEUE = 1; // Kapasitas maksimum antrean
const int MAX_RIWAYAT = MAX_SLOT * 2;


// Struktur data riwayat parkir
string riwayatParkir[MAX_RIWAYAT];
string waktuMasukRiwayat[MAX_RIWAYAT];
string waktuKeluarRiwayat[MAX_RIWAYAT];
int jumlahRiwayat = 0;


// Fungsi untuk mendapatkan waktu saat ini dalam format %Y-%m-%d %H:%M:%S
string getWaktuSekarang() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

    return string(buffer);
}

// Fungsi untuk menampilkan garis horizontal
void garisHorizontal(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}


// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "| 4. Lihat Riwayat Parkir                |\n";
    cout << "| 0. Keluar                              |\n";
    cout << "Pilihan: ";
}

// Fungsi untuk melihat riwayat parkir
void lihatRiwayatParkir() {
    garisHorizontal(41);
    cout << "|              RIWAYAT PARKIR             |\n";
    garisHorizontal(41);

    if (jumlahRiwayat == 0) {
        cout << "Belum ada riwayat parkir.\n";
    } else {
        for (int i = 0; i < jumlahRiwayat; i++) {
            cout << "\n++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "+ Riwayat Ke : " << i + 1 << "\n";
            cout << "+ Plat       : " << riwayatParkir[i] << "\n";
            cout << "+ Masuk      : " << waktuMasukRiwayat[i] << "\n";
            cout << "+ Keluar     : " << waktuKeluarRiwayat[i] << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
        }
    }
    cout << "\n";
}


int main() {
    int pilihan;

    do {
        system("cls");
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();
        system("cls");

        switch (pilihan) {
            
            case 4:
                lihatRiwayatParkir();
                system("pause");
                system("cls");
                break;
            }
    } while (pilihan != 0);
	return 0;
}
