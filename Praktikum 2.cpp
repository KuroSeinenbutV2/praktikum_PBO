#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Kelas Menu untuk menyimpan menu makanan dan harga
class Menu {
private:
    map<string, double> foodItems;

public:
    // Menambahkan item ke dalam menu
    void addItem(const string& itemName, double price) {
        foodItems[itemName] = price;
    }

    // Menampilkan menu makanan
    void displayMenu() const {
        cout << "Menu Makanan:\n";
        cout << fixed << setprecision(2); // Menampilkan harga dengan 2 angka desimal
        for (const auto& item : foodItems) {
            cout << item.first << " - Rp " << item.second << endl;
        }
    }

    // Mengambil harga makanan berdasarkan nama item
    double getPrice(const string& itemName) const {
        auto it = foodItems.find(itemName);
        if (it != foodItems.end()) {
            return it->second;
        }
        return 0.0; // Mengembalikan 0 jika item tidak ditemukan
    }
};

// Kelas Kasir untuk mengelola pesanan dan pembayaran
class Kasir {
private:
    Menu& menu;
    map<string, int> orders;
    double totalAmount;

public:
    Kasir(Menu& m) : menu(m), totalAmount(0.0) {}

    // Menambahkan pesanan ke daftar
    void addOrder(const string& itemName, int quantity) {
        double price = menu.getPrice(itemName);
        if (price > 0) {
            orders[itemName] += quantity;
            totalAmount += price * quantity;
        } else {
            cout << "Item " << itemName << " tidak ditemukan dalam menu.\n";
        }
    }

    // Menampilkan pesanan yang telah dilakukan
    void displayOrder() const {
        cout << "Pesanan Anda:\n";
        for (const auto& order : orders) {
            double price = menu.getPrice(order.first);
            cout << order.first << " x " << order.second << " - Rp " << price * order.second << endl;
        }
        cout << "Total yang harus dibayar: Rp " << totalAmount << endl;
    }

    // Menghitung uang kembalian
    void processPayment(double payment) {
        if (payment >= totalAmount) {
            double change = payment - totalAmount;
            cout << "Jumlah uang kembalian: Rp " << change << endl;
        } else {
            cout << "Jumlah uang tidak cukup! Total yang harus dibayar adalah Rp " << totalAmount << endl;
        }
    }
};

int main() {
    // Membuat objek menu dan menambahkan beberapa item
    Menu menu;
    menu.addItem("Nasi Goreng", 15000);
    menu.addItem("Mie Ayam", 12000);
    menu.addItem("Sate", 20000);

    // Menampilkan menu makanan
    menu.displayMenu();

    // Membuat objek kasir dengan referensi ke objek menu
    Kasir kasir(menu);

    // Input data dari pengguna
    string item;
    int quantity;
    cout << "\nMasukkan pesanan Anda:\n";
    while (true) {
        cout << "Nama makanan (ketik 'selesai' untuk mengakhiri): ";
        cin >> item;
        if (item == "selesai") break;

        cout << "Jumlah: ";
        cin >> quantity;
        kasir.addOrder(item, quantity);
    }

    // Menampilkan pesanan dan total
    kasir.displayOrder();

    // Input pembayaran
    double payment;
    cout << "Masukkan jumlah uang yang dibayar: Rp ";
    cin >> payment;
    kasir.processPayment(payment);

    return 0;
}
