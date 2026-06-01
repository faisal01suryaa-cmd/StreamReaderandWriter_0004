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
