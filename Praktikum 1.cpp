#include <iostream>
#include <string>
using namespace std;

class Karyawan { //Declare Class
private: //Declare Attribute
    string nama;
    string jabatan;
    int lembur;
    int dinas;
    int presensi;
    int gajiPokok;

public: //Declare Attribute
    Karyawan(string nama, string jabatan, int lembur, int dinas, int presensi) //Constructor
    {
        this->nama = nama;
        this->jabatan = jabatan;
        this->lembur = lembur;
        this->dinas = dinas;
        this->presensi = presensi;

        if (jabatan == "teknisi") gajiPokok = 1800000;
        else if (jabatan == "rnd") gajiPokok = 2300000;
        else if (jabatan == "kadiv") gajiPokok = 2700000;
        else gajiPokok = 0;
    }

    int HitungGaji() { //Declare Method to calculate salary
        return gajiPokok + (lembur * 20000) + (dinas * 400000) + (presensi * 50000);
    }

    void InfoKaryawan() { //Declare Method to display employees information
    	cout << endl;
        cout << "-----------------------------------" << endl;
        cout << "Nama karyawan: " << nama << endl;
        cout << "Jumlah presensi dalam satu bulan: " << presensi << endl;
        cout << "Jumlah dinas luar: " << dinas << endl;
        cout << "Total gaji: Rp " << HitungGaji() << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() { //Main Function
    string nama, jabatan;
    int lembur, dinas, presensi;

    cout << "Masukkan Nama Karyawan: ";
    getline(cin, nama);
    cout << "Masukkan Jabatan (teknisi / rnd / kadiv): ";
    getline(cin, jabatan);
    cout << "Masukkan Jumlah Jam Lembur: ";
    cin >> lembur;
    cout << "Masukkan Jumlah Dinas Luar: ";
    cin >> dinas;
    cout << "Masukkan Jumlah Presensi: ";
    cin >> presensi;

    Karyawan karyawan(nama, jabatan, lembur, dinas, presensi);  //Make new employees object with data that inputed before
    karyawan.InfoKaryawan(); //Display the new employees object data

    return 0;
}
