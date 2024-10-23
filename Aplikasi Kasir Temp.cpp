#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Produk {
    int id;
    string nama;
    int harga;
    int stok;
};

void tampilkanHeader() {
    cout << "==============================================" << endl;
    cout << "|                                            |" << endl;
    cout << "|        ===  APLIKASI KASIR SUPERMARKET ===  |" << endl;
    cout << "|                                            |" << endl;
    cout << "==============================================" << endl;
}

void tampilkanMenu() {
    cout << "==============================================" << endl;
    cout << "|                MENU UTAMA                  |" << endl;
    cout << "|  1. Tambah Produk                          |" << endl;
    cout << "|  2. Tampilkan Produk                       |" << endl;
    cout << "|  3. Update Produk                          |" << endl;
    cout << "|  4. Hapus Produk                           |" << endl;
    cout << "|  5. Transaksi                              |" << endl;
    cout << "|  6. Simpan Data                            |" << endl;
    cout << "|  7. Keluar                                 |" << endl;
    cout << "==============================================" << endl;
}

// Fungsi untuk menambahkan produk
void tambahProduk(vector<Produk> &produkList) {
    Produk p;
    cout << "Masukkan ID produk: ";
    cin >> p.id;
    cout << "Masukkan nama produk: ";
    cin >> p.nama;
    cout << "Masukkan harga produk: ";
    cin >> p.harga;
    cout << "Masukkan stok produk: ";
    cin >> p.stok;
    produkList.push_back(p);
    cout << "Produk berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua produk
void tampilkanProduk(const vector<Produk> &produkList) {
    cout << "==============================================" << endl;
    cout << "|                DAFTAR PRODUK               |" << endl;
    cout << "==============================================" << endl;
    for (const auto &p : produkList) {
        cout << "| ID: " << p.id << " | Nama: " << p.nama
             << " | Harga: " << p.harga << " | Stok: " << p.stok << " |" << endl;
    }
    cout << "==============================================" << endl;
}

// Fungsi untuk menyimpan data produk ke file
void simpanData(const vector<Produk> &produkList) {
    ofstream file("database.txt");
    for (const auto &p : produkList) {
        file << p.id << " " << p.nama << " " << p.harga << " " << p.stok << endl;
    }
    file.close();
    cout << "Data berhasil disimpan!" << endl;
}

// Fungsi untuk membaca data produk dari file
void bacaData(vector<Produk> &produkList) {
    ifstream file("database.txt");
    Produk p;
    while (file >> p.id >> p.nama >> p.harga >> p.stok) {
        produkList.push_back(p);
    }
    file.close();
}

int main() {
    vector<Produk> produkList;
    bacaData(produkList); // Baca data dari file saat aplikasi dimulai

    int pilihan;
    tampilkanHeader(); // Tampilkan header aplikasi

    do {
        tampilkanMenu(); // Tampilkan menu dengan ASCII art
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahProduk(produkList);
                break;
            case 2:
                tampilkanProduk(produkList);
                break;
            case 6:
                simpanData(produkList);
                break;
            case 7:
                cout << "==============================================" << endl;
                cout << "|  Terima kasih telah menggunakan aplikasi!  |" << endl;
                cout << "==============================================" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 7);

    return 0;
}

