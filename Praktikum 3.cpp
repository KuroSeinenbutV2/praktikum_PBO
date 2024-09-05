#include <iostream>
#include <string>
using namespace std;

class Tabungan {
private:
    int saldo;

public:
    Tabungan() {
        saldo = 0;
    }

    int getSaldo() {
        return saldo;
    }

    void simpanUang(int jumlah, string mataUang) {
        if (mataUang == "IDR") {
            saldo += jumlah;
        } else if (mataUang == "Yuan") {
            saldo += jumlah * 3000;
        } else if (mataUang == "USD") {
            saldo += jumlah * 15000;
        } else {
            cout << "Mata uang tidak dikenali!" << endl;
        }
    }

    void ambilUang(int jumlah, string mataUang) {
        int jumlahIDR = 0;
        
        if (mataUang == "IDR") {
            jumlahIDR = jumlah;
        } else if (mataUang == "Yuan") {
            jumlahIDR = jumlah * 3000;
        } else if (mataUang == "USD") {
            jumlahIDR = jumlah * 15000;
        } else {
            cout << "Mata uang tidak dikenali!" << endl;
            return;
        }

        if (jumlahIDR > saldo) {
            cout << "Saldo tidak cukup!" << endl;
        } else {
            saldo -= jumlahIDR;
            cout << "Uang berhasil diambil: " << jumlah << " " << mataUang << endl;
        }
    }
};

int main() {
    Tabungan tabungan;
    int pilihan;
    int jumlah;
    string mataUang;

    while (true) {
        cout << "\n=== Menu Tabungan ===" << endl;
        cout << "1. Simpan Uang" << endl;
        cout << "2. Ambil Uang" << endl;
        cout << "3. Cek Saldo" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan jumlah uang yang akan disimpan: ";
                cin >> jumlah;
                cout << "Pilih mata uang (1: IDR, 2: YUAN, 3: USD): ";
                cin >> pilihan;
                if (pilihan == 1) {
                    mataUang = "IDR";
                } else if (pilihan == 2) {
                    mataUang = "Yuan";
                } else if (pilihan == 3) {
                    mataUang = "USD";
                }
                tabungan.simpanUang(jumlah, mataUang);
                break;

            case 2:
                cout << "Masukkan jumlah uang yang akan diambil: ";
                cin >> jumlah;
                cout << "Pilih mata uang (1: IDR, 2: YUAN, 3: USD): ";
                cin >> pilihan;
                if (pilihan == 1) {
                    mataUang = "IDR";
                } else if (pilihan == 2) {
                    mataUang = "Yuan";
                } else if (pilihan == 3) {
                    mataUang = "USD";
                }
                tabungan.ambilUang(jumlah, mataUang);
                break;

            case 3:
                cout << "Saldo saat ini: Rp " << tabungan.getSaldo() << endl;
                break;

            case 4:
                cout << "Keluar !" << endl;
                return 0;

            default:
                cout << "Pilih 1/2/3" << endl;
        }
    }

    return 0;
}
