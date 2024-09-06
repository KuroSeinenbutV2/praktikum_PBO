#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Mahasiswa {
private:
    string nama;
    string nim;
    double nilai;

public:
    Mahasiswa(string nama, string nim) : nama(nama), nim(nim), nilai(0.0) {}

    void isiData() {
        cout << "Masukkan nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
    }

    void lihatNilai() const {
        cout << "Nilai " << nama << " (NIM: " << nim << "): " << nilai << endl;
    }

    void ubahNilai(double nilaiBaru) {
        nilai = nilaiBaru;
        cout << "Nilai berhasil diubah." << endl;
    }

    string getNama() const { return nama; }
    string getNIM() const { return nim; }
};

class ManajemenMahasiswa {
private:
    vector<Mahasiswa> daftarMahasiswa;

public:
    void tambahMahasiswa() {
        Mahasiswa mhs("", "");
        mhs.isiData();
        daftarMahasiswa.push_back(mhs);
        cout << "Mahasiswa berhasil ditambahkan." << endl;
    }

    void lihatNilaiMahasiswa(const string& nim) {
        for (const auto& mhs : daftarMahasiswa) {
            if (mhs.getNIM() == nim) {
                mhs.lihatNilai();
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    void ubahNilaiMahasiswa(const string& nim, double nilaiBaru) {
        for (auto& mhs : daftarMahasiswa) {
            if (mhs.getNIM() == nim) {
                mhs.ubahNilai(nilaiBaru);
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }
};

int main() {
    ManajemenMahasiswa manajemen;
    int pilihan;
    string nim;
    double nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Lihat Nilai Mahasiswa\n";
        cout << "3. Ubah Nilai Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                manajemen.tambahMahasiswa();
                break;
            case 2:
                cout << "Masukkan NIM mahasiswa: ";
                getline(cin, nim);
                manajemen.lihatNilaiMahasiswa(nim);
                break;
            case 3:
                cout << "Masukkan NIM mahasiswa: ";
                getline(cin, nim);
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                manajemen.ubahNilaiMahasiswa(nim, nilai);
                break;
            case 0:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}