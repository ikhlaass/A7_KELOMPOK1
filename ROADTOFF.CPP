#include <iostream>
using namespace std;

void garis (int nomor) {
	for(int i = 0; i < nomor; i++){
		cout << "-";
	}
	cout << endl;
}

int main() {
garis(42);
cout << "|          Aplikasi Parkir Mobil         |\n";
garis(42);
cout << "|1. Masukkan Mobil                       |\n";
cout << "|2. Keluarkan Mobil                      |\n";
cout << "|3. Lihat Slot Parkir                    |\n";
cout << "|4. Lihat Riwayat Parkir                 |\n";
cout << "|5. Lihat Antrean                        |\n";
cout << "|6. Laporan Pendapatan                   |\n";
cout << "|0. Keluar                               |\n";
cout << "pilihan";


garis(42);
cout << "|          Aplikasi Parkir Mobil         |\n";
garis(42);
cout << "|1. Masukkan Mobil                       |\n";
cout << "|2. Keluarkan Mobil                      |\n";

cout << "|0. Keluar                               |\n";
cout << "pilihan";
}
