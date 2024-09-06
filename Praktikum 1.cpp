#include <iostream>
#include <string>
using namespace std;

enum Jabatan { TEKNISI = 1, RND = 2, KADIV = 3, NGGANGUR };

class Karyawan { // Declare Class
private: // Declare Attribute
    string nama;
    Jabatan jabatan;
    int lembur;
    int dinas;
    int presensi;
    int gajiPokok;

public: // Declare Attribute
    Karyawan(string nama, Jabatan jabatan, int lembur, int dinas, int presensi) // Constructor
    {
        this->nama = nama;
        this->jabatan = jabatan;
        this->lembur = lembur;
        this->dinas = dinas;
        this->presensi = presensi;

        switch (jabatan) {
            case TEKNISI: gajiPokok = 1800000; break;
            case RND: gajiPokok = 2300000; break;
            case KADIV: gajiPokok = 2700000; break;
            case NGGANGUR: gajiPokok = 0; break;
            default: gajiPokok = 0; break;
        }
    }

    int HitungGaji() { // Declare Method to calculate salary
        return gajiPokok + (lembur * 20000) + (dinas * 400000) + (presensi * 50000);
    }

    void InfoKaryawan() { // Declare Method to display employees information
        cout << endl;
        cout << "-----------------------------------" << endl;
        cout << "Nama karyawan: " << nama << endl;
        cout << "Jumlah presensi dalam satu bulan: " << presensi << endl;
        cout << "Jumlah dinas luar: " << dinas << endl;
        cout << "Total gaji: Rp " << HitungGaji() << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() { // Main Function
    string nama;
    int jabatanInput, lembur, dinas, presensi;
    Jabatan jabatan;

    cout << "Masukkan Nama Karyawan: ";
    getline(cin, nama);

    cout << "Pilih Jabatan (1. Teknis / 2. RND / 3. Kadiv): ";
    cin >> jabatanInput;
    switch (jabatanInput) {
        case TEKNISI: jabatan = TEKNISI; break;
        case RND: jabatan = RND; break;
        case KADIV: jabatan = KADIV; break;
        default: jabatan = NGGANGUR;
    }

    cout << "Masukkan Jumlah Jam Lembur: ";
    cin >> lembur;
    cout << "Masukkan Jumlah Dinas Luar: ";
    cin >> dinas;
    cout << "Masukkan Jumlah Presensi: ";
    cin >> presensi;

    Karyawan karyawan(nama, jabatan, lembur, dinas, presensi); // Make new employees object with data that inputed before
    karyawan.InfoKaryawan(); // Display the new employees object data

    return 0;
}
