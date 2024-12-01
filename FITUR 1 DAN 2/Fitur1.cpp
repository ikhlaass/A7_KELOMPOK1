#include <iostream>
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

int main() {
    masukkanMobil();
    system("read");
    system("clear");
               
}
