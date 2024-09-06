#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class ItemMakanan {
public:
    string nama;
    double harga;
    ItemMakanan(string n, double h) : nama(n), harga(h) {}
};

class Restaurant {
private:
    vector<ItemMakanan> menu;

public:
    Restaurant() {
        menu.push_back(ItemMakanan("Nasi Goreng", 13000));
        menu.push_back(ItemMakanan("Mie Goreng", 13000));
        menu.push_back(ItemMakanan("Ayam Penyet", 13000));
        menu.push_back(ItemMakanan("Ayam Geprek", 10000));
        menu.push_back(ItemMakanan("Es Teh", 3000));
        menu.push_back(ItemMakanan("Es Jeruk", 6000 ));
        menu.push_back(ItemMakanan("Nutrisari", 5000 ));
    }

    void displayMenu() {
        cout << "=== Menu Makanan ===" << endl;
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i].nama << " - Rp " << menu[i].harga << endl;
        }
        cout << "====================" << endl;
    }

    double hitungTotal(const vector<int>& orders, const vector<int>& quantities) {
        double total = 0;
        for (size_t i = 0; i < orders.size(); i++) {
            total += menu[orders[i]].harga * quantities[i];
        }
        return total;
    }
};

int main() {
    Restaurant restaurant;
    vector<int> orders;
    vector<int> quantities;

    int choice, quantity;
    char more;

    restaurant.displayMenu();

    do {
        cout << "Pilih makanan (masukkan nomor): ";
        cin >> choice;
        cout << "Jumlah: ";
        cin >> quantity;

        // Menyimpan pesanan
        orders.push_back(choice - 1);
        quantities.push_back(quantity);

        cout << "Apakah ada pesanan lain? (y/n): ";
        cin >> more;
    } while (more == 'y' || more == 'Y');

    // Menghitung total
    double total = restaurant.hitungTotal(orders, quantities);
    cout << fixed << setprecision(2);
    cout << "Total yang harus dibayar: Rp " << total << endl;

    double bayar;
    cout << "Masukkan jumlah uang pembayaran: Rp ";
    cin >> bayar;

    if (bayar >= total) {
        double kembalian = bayar - total;
        cout << "Jumlah uang kembalian: Rp " << kembalian << endl;
    } else {
        cout << "Uang pembayaran tidak cukup!" << endl;
    }

    return 0;
}
