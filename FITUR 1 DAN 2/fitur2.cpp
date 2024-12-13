#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SLOT = 10; 
const int MAX_QUEUE = 10; 
const int MAX_RIWAYAT = MAX_SLOT * 2; 

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

void simpanAntrean() {
    ofstream file("antreanMobil.txt");
    if (file.is_open()) {
        for (int i = frontAntrean; i <= rearAntrean; i++) {
            file << antreanMobil[i] << "," << waktuAntrean[i] << endl;
        }
        file.close();
    }
}

void simpanSlotParkir() {
    ofstream file("slotParkir.txt");
    if (file.is_open()) {
        for (int i = 0; i < MAX_SLOT; i++) {
            file << slotParkir[i] << "," << waktuParkir[i] << endl;
        }
        file.close();
    }
}

void keluarkanMobil() {
    string platNomor;
    garisHorizontal(41);
    cout << "|           MENGELUARKAN MOBIL           |\n";
    garisHorizontal(41);

    cout << "Masukkan plat nomor mobil yang akan dikeluarkan: ";
    getline(cin, platNomor);

    bool ditemukan = false;
    for (int i = 0; i < MAX_SLOT; i++) {
        if (slotParkir[i] == platNomor) {
            ditemukan = true;

            riwayatParkir[jumlahRiwayat] = slotParkir[i];
            waktuMasukRiwayat[jumlahRiwayat] = waktuParkir[i];
            waktuKeluarRiwayat[jumlahRiwayat] = getWaktuSekarang();
            jumlahRiwayat++;

            slotParkir[i].clear();
            waktuParkir[i].clear();

            pendapatan += 5000;


                cout << "\n\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++\n";
                cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
                cout << "+ Date          : " << getWaktuSekarang() << "\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";

                if (jumlahAntrean > 0) {
                slotParkir[i] = antreanMobil[frontAntrean];
                waktuParkir[i] = waktuAntrean[frontAntrean];

                for (int j = frontAntrean; j < rearAntrean; j++) {
                    antreanMobil[j] = antreanMobil[j + 1];
                    waktuAntrean[j] = waktuAntrean[j + 1];
                }
                rearAntrean--;
                jumlahAntrean--;

                cout << "Mobil dengan plat " << slotParkir[i] << " dipindahkan dari antrean ke slot " << i + 1 << ".\n";
                simpanAntrean();  
                simpanSlotParkir(); 
            }

            break;
        }
    }

    if (!ditemukan) {
        cout << "Mobil dengan plat " << platNomor << " tidak ditemukan di slot parkir.\n";
    }
}

int main() {
    keluarkanMobil();
    system("read");
    system("clear");
}