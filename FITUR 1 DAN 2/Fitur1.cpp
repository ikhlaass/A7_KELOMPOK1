#include <iostream>
#include <fstream>
#include <ctime> 
using namespace std;

#define MAX_SLOT 10
#define MAX_QUEUE 10

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

bool slotKosong(int slot) {
    return slotParkir[slot].empty();
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

void simpanAntrean() {
    ofstream file("antreanMobil.txt");
    if (file.is_open()) {
        for (int i = frontAntrean; i <= rearAntrean; i++) {
            file << antreanMobil[i] << "," << waktuAntrean[i] << endl;
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

void masukkanMobil() {
    string platNomor;
    garisHorizontal(41);
    cout << "|           MENAMBAHKAN MOBIL           |\n";
    garisHorizontal(41);
    
    cout << "Masukkan plat nomor mobil: ";
    getline(cin, platNomor);

    cout << "Pilih slot parkir (1-" << MAX_SLOT << "): ";
    int slot;
    cin >> slot;
    cin.ignore(); 

    if (slot < 1 || slot > MAX_SLOT) {
        cout << "Slot tidak valid. Silakan coba lagi.\n";
        return;
    }

    slot--; 

    if (slotKosong(slot)) {
        slotParkir[slot] = platNomor;
        waktuParkir[slot] = getWaktuSekarang();

        cout << "\n\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "+ Mobil Plat    : " << platNomor << "\n"; 
        cout << "+ Slot          : " << slot + 1 << "\n";                                                                 
        cout << "+ Harga         : " << "5.000" << "\n";                                                                 
        cout << "+ Date          : " << getWaktuSekarang() << "\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";

    } else {
        if (jumlahAntrean < MAX_QUEUE) {
            rearAntrean++;
            antreanMobil[rearAntrean] = platNomor;
            waktuAntrean[rearAntrean] = getWaktuSekarang();
            jumlahAntrean++;

            cout << "\n\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "\nParkir penuh. Mobil Masuk Ke Daftar Antrian.\n";
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
    system("clear");
    masukkanMobil();
    return 0;
}
