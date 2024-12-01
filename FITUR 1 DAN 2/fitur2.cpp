#include <iostream>
using namespace std;

const int MAX_SLOT = 1; // Kapasitas maksimum slot parkir
const int MAX_QUEUE = 1; // Kapasitas maksimum antrean
const int MAX_RIWAYAT = MAX_SLOT * 2; // Kapasitas maksimum riwayat

// Struktur data parkir
string slotParkir[MAX_SLOT];
string waktuParkir[MAX_SLOT];
int jumlahSlotTerisi = 0;

// Struktur data riwayat parkir
string riwayatParkir[MAX_RIWAYAT];
string waktuMasukRiwayat[MAX_RIWAYAT];
string waktuKeluarRiwayat[MAX_RIWAYAT];
int jumlahRiwayat = 0;

// Struktur data antrean
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
    keluarkanMobil();
    system("read");
    system("clear");
}