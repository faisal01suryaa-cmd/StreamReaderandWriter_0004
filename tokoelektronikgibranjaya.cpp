#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <stdexcept>
#include <vector>
using namespace std;

class TokoElektronik {
private:
    
    array<string, 3> faisal; 

public:
    
    TokoElektronik() {
        faisal = {"Laptop Asus ROG", "Smartphone Samsung S24", "Smart TV LG 4K"};
    }

    
    string ambilProduk(size_t nomorRak) {
        try {
            
            return faisal.at(nomorRak);
        } 
        catch (const out_of_range& e) {
            
            string pesanError = "Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) + " kosong atau tidak tersedia!";
            throw runtime_error(pesanError);
        }
    }
};

void readGudang() {
    ifstream infile("gudang.txt");
    cout << "\n=== Daftar Barang di Gudang (gudang.txt) ===" << endl;
    
    if (!infile.is_open()) {
        cout << "File gudang.txt belum ada atau kosong." << endl;
        return;
    }
    
    string baris;
    int no = 1;
    bool isEmpty = true;
    while (getline(infile, baris)) {
        cout << "- " << baris << endl;
        isEmpty = false;
    }
    
    if (isEmpty) {
        cout << "(Gudang Kosong)" << endl;
    }
    infile.close();
}

void createBarang() {
    ofstream outfile("gudang.txt", ios::app);
    string namaBarang;
    
    cout << "Masukkan nama barang baru yang ingin ditambahkan ke gudang: ";
    cin.ignore();
    getline(cin, namaBarang);
    
    outfile << namaBarang << endl;
    outfile.close();
    cout << "Barang berhasil ditambahkan ke dalam file" << endl;
}

void updateBarang() {
    vector<string> daftarBarang;
    ifstream infile("gudang.txt");
    string baris;
    
    while (getline(infile, baris)) {
        daftarBarang.push_back(baris);
    }
    infile.close();

    if (daftarBarang.empty()) {
        cout << "Gudang masih kosong, tidak ada yang bisa di-update." << endl;
        return;
    }

    cout << "\nPilih urutan barang yang ingin diubah (1 - " << daftarBarang.size() << "): ";
    int target;
    cin >> target;

    if (target < 1 || target > daftarBarang.size()) {
        cout << "Nomor tidak valid!" << endl;
        return;
    }

    cout << "Masukkan nama barang baru: ";
    cin.ignore();
    string namaBaru;
    getline(cin, namaBaru);

    daftarBarang[target - 1] = namaBaru;

    ofstream outfile("gudang.txt", ios::trunc);
    for (const string& b : daftarBarang) {
        outfile << b << endl;
    }
    outfile.close();
    cout << "Barang berhasil diperbarui!" << endl;
}

void deleteBarang() {
    vector<string> daftarBarang;
    ifstream infile("gudang.txt");
    string baris;
    
    while (getline(infile, baris)) {
        daftarBarang.push_back(baris);
    }
    infile.close();

    if (daftarBarang.empty()) {
        cout << "Gudang masih kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    cout << "\nPilih urutan barang yang ingin dihapus (1 - " << daftarBarang.size() << "): ";
    int target;
    cin >> target;

    if (target < 1 || target > daftarBarang.size()) {
        cout << "Nomor tidak valid!" << endl;
        return;
    }

    daftarBarang.erase(daftarBarang.begin() + target - 1);

    ofstream outfile("gudang.txt", ios::trunc);
    for (const string& b : daftarBarang) {
        outfile << b << endl;
    }
    outfile.close();
    cout << "Barang berhasil dihapus!" << endl;
} 

int main() {
    TokoElektronik toko;
    int pilihan;

    do {
        cout << "\n============================================" << endl;
        cout << "   Sistem Manajemen Toko Gibran Jaya        " << endl;
        cout << "============================================" << endl;
        
        readGudang(); 
        
        cout << "\nMenu Utama CRUD & Etalase:" << endl;
        cout << "1. Tambah Barang Gudang " << endl;
        cout << "2. Ubah Barang Gudang " << endl;
        cout << "3. Hapus Barang Gudang " << endl;
        cout << "4. Jalankan Simulasi Etalase" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan Pilihan (1-5): ";
        cin >> pilihan;
