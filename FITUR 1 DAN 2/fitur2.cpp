#include <iostream>
#include <fstream>

using namespace std;

#define MAX_SLOT 10
#define MAX_QUEUE 10
#define MAX_RIWAYAT (MAX_SLOT * 2)

string slotParkir[MAX_SLOT];
string waktuParkir[MAX_SLOT];
int jumlahSlotTerisi = 0;

string riwayatParkir[MAX_RIWAYAT];
string waktuMasukRiwayat[MAX_RIWAYAT];
string waktuKeluarRiwayat[MAX_RIWAYAT];
int jumlahRiwayat = 0;

string waktuAntrean[MAX_QUEUE];
string antreanMobil[MAX_QUEUE];
int frontAntrean = 0, rearAntrean = -1, jumlahAntrean = 0;

float pendapatan = 0;

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

void bacaAntrean() {
    ifstream file("antreanMobil.txt");
    if (file.is_open()) {
        string platNomor, waktu;
        while (getline(file, platNomor, ',') && getline(file, waktu)) {
            antreanMobil[rearAntrean + 1] = platNomor;
            waktuAntrean[rearAntrean + 1] = waktu;
            rearAntrean++;
            jumlahAntrean++;
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

void bacaSlotParkir() {
    ifstream file("slotParkir.txt");
    if (file.is_open()) {
        string platNomor, waktu;
        int i = 0;
        while (getline(file, platNomor, ',') && getline(file, waktu)) {
            slotParkir[i] = platNomor;
            waktuParkir[i] = waktu;
            i++;
        }
        file.close();
    }
}

void simpanRiwayatParkir() {
    ofstream file("riwayatParkir.txt");
    if (file.is_open()) {
        for (int i = 0; i < jumlahRiwayat; i++) {
            file << riwayatParkir[i] << "," << waktuMasukRiwayat[i] << "," << waktuKeluarRiwayat[i] << endl;
        }
        file.close();
    }
}

void bacaRiwayatParkir() {
    ifstream file("riwayatParkir.txt");
    if (file.is_open()) {
        string platNomor, waktuMasuk, waktuKeluar;
        while (getline(file, platNomor, ',') && getline(file, waktuMasuk, ',') && getline(file, waktuKeluar)) {
            riwayatParkir[jumlahRiwayat] = platNomor;
            waktuMasukRiwayat[jumlahRiwayat] = waktuMasuk;
            waktuKeluarRiwayat[jumlahRiwayat] = waktuKeluar;
            jumlahRiwayat++;
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
            cout << "\nData Mobil Yang Keluar .\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
            cout << "+ Date          : " << getWaktuSekarang() << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";
            simpanRiwayatParkir();

                if (jumlahAntrean > 0) {
                slotParkir[i] = antreanMobil[frontAntrean];
                waktuParkir[i] = waktuAntrean[frontAntrean];

                for (int j = frontAntrean; j < rearAntrean; j++) {
                    antreanMobil[j] = antreanMobil[j + 1];
                    waktuAntrean[j] = waktuAntrean[j + 1];
                }
                rearAntrean--;
                jumlahAntrean--;

                cout << "Mobil dengan plat " << slotParkir[i] << " dipindahkan dari antrean ke slot.\n";
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