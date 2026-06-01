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
