#include <iostream>
using namespace std;

const int MAX_SLOT = 1; 
const int MAX_QUEUE = 1; 
const int MAX_RIWAYAT = MAX_SLOT * 10;

string slotParkir[MAX_SLOT];
string waktuParkir[MAX_SLOT];
int jumlahSlotTerisi = 0;

string riwayatParkir[MAX_RIWAYAT];
string waktuMasukRiwayat[MAX_RIWAYAT];
string waktuKeluarRiwayat[MAX_RIWAYAT];
int jumlahRiwayat = 0;

string waktuAntrean[MAX_SLOT];
string antreanMobil[MAX_QUEUE];
int frontAntrean = 0, rearAntrean = -1, jumlahAntrean = 0;

int pendapatan = 0;

string getWaktuSekarang() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

    return string(buffer);
}

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
    garisHorizontal(41);
    cout << "Pilihan: ";
}


void masukkanMobil() {
    if (jumlahSlotTerisi < MAX_SLOT) {
        string platNomor;
        garisHorizontal(41);
        cout << "|           MENAMBAHKAN MOBIL           |\n";
        garisHorizontal(41);
        cout << "Masukkan plat nomor mobil: ";
        getline(cin, platNomor);

        slotParkir[jumlahSlotTerisi] = platNomor;
        waktuParkir[jumlahSlotTerisi] = getWaktuSekarang();
        jumlahSlotTerisi++;

        cout << "\n\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
        cout << "+ Date          : " << getWaktuSekarang() << "\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";

        cout << "berhasil diparkir.\n";
    
    } else {
        if (jumlahAntrean < MAX_QUEUE) {
            string platNomor;
            cout << "Parkir penuh. Masukkan plat nomor mobil ke antrean: ";
            getline(cin, platNomor);

            rearAntrean++;
            antreanMobil[rearAntrean] = platNomor;
            waktuAntrean[rearAntrean] = getWaktuSekarang();
            jumlahAntrean++;

            cout << "\n\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
            cout << "+ Date          : " << getWaktuSekarang() << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";
        } else {
            cout << "Parkir penuh dan antrean juga penuh. Tidak dapat menerima mobil lagi.\n";
        }
    }
}

// Fungsi untuk mengeluarkan mobil dari slot parkir
void keluarkanMobil() {
    garisHorizontal(41);
    cout << "|           MENGELUARKAN MOBIL           |\n";
    garisHorizontal(41);
    if (jumlahSlotTerisi > 0) {
        string platNomor;
        cout << "Masukkan plat nomor mobil yang akan dikeluarkan: ";
        getline(cin, platNomor);

        bool ditemukan = false;
        for (int i = 0; i < jumlahSlotTerisi; i++) {
            if (slotParkir[i] == platNomor) {
                ditemukan = true;

                // Tambahkan ke riwayat
                riwayatParkir[jumlahRiwayat] = slotParkir[i];
                waktuMasukRiwayat[jumlahRiwayat] = waktuParkir[i];
                waktuKeluarRiwayat[jumlahRiwayat] = getWaktuSekarang();
                jumlahRiwayat++;

                // Geser slot parkir
                for (int j = i; j < jumlahSlotTerisi - 1; j++) {
                    slotParkir[j] = slotParkir[j + 1];
                    waktuParkir[j] = waktuParkir[j + 1];
                }

                jumlahSlotTerisi--;
                pendapatan += 5000;

                cout << "\n\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++\n";
                cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
                cout << "+ Date          : " << getWaktuSekarang() << "\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";

                // Jika ada antrean, tambahkan ke slot parkir
                if (jumlahAntrean > 0) {
                    slotParkir[jumlahSlotTerisi] = antreanMobil[frontAntrean];
                    waktuParkir[jumlahSlotTerisi] = getWaktuSekarang();
                    jumlahSlotTerisi++;

                    for (int i = frontAntrean; i < rearAntrean; i++) {
                    antreanMobil[i] = antreanMobil[i + 1];
                    waktuAntrean[i] = waktuAntrean[i + 1];
                    }

                    frontAntrean++;
                    jumlahAntrean--;
                }
                break;
            }
        }

        if (!ditemukan) {
            cout << "[" << getWaktuSekarang() << "] Mobil dengan plat " << platNomor << " tidak ditemukan di slot parkir.\n";
        }
    } else {
        cout << "[" << getWaktuSekarang() << "] Tidak ada mobil di slot parkir.\n";
    }
}

int main() {
	int pilihan;
    
	do {
        system("clear");
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();
        system("clear");

        switch (pilihan) {
            case 1:
                masukkanMobil();
                system("read");
                system("clear");
                break;
            case 2:
                keluarkanMobil();
                system("read");
                system("clear");
                break;
            case 0:
                cout << "Keluar dari aplikasi.\n";
                system("read");
                system("clear");
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                system("read");
                system("clear");
	    } 
    } while (pilihan != 0);
}
