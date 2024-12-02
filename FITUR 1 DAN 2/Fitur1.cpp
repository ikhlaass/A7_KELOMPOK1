#include <iostream>
#include <fstream>
#include <ctime> 
using namespace std;

const int MAX_SLOT = 1; 
const int MAX_QUEUE = 1;

string slotParkir[MAX_SLOT];
string waktuParkir[MAX_SLOT];
int jumlahSlotTerisi = 0;

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

void simpanKeFile(string platNomor, string waktu) {
    ofstream file("data_parkir.txt"); 
    if (file.is_open()) {
        file << "Plat Nomor : " << platNomor << endl;
        file << "Waktu      : " << waktu << endl;
        file << "----------------------------------------\n";
        file.close();
        cout << "Data berhasil disimpan ke file data_parkir.txt\n";
    } else {
        cout << "Gagal membuka file untuk menyimpan data.\n";
    }
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

        simpanKeFile(platNomor, waktuParkir[jumlahSlotTerisi - 1]);

        cout << "\n\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
        cout << "+ Date          : " << waktuParkir[jumlahSlotTerisi - 1] << "\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";

        cout << "Berhasil diparkir.\n";
    } else {
        if (jumlahAntrean < MAX_QUEUE) {
            string platNomor;
            cout << "Parkir penuh. Masukkan plat nomor mobil ke antrean: ";
            getline(cin, platNomor);

            rearAntrean++;
            antreanMobil[rearAntrean] = platNomor;
            waktuAntrean[rearAntrean] = getWaktuSekarang();
            jumlahAntrean++;

            simpanKeFile(platNomor, waktuAntrean[rearAntrean]);

            cout << "\n\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
            cout << "+ Date          : " << waktuAntrean[rearAntrean] << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";
        } else {
            cout << "Parkir penuh dan antrean juga penuh. Tidak dapat menerima mobil lagi.\n";
        }
    }
}

int main() {
    masukkanMobil();
    return 0;
}
