#include <iostream>

// Fungsi manual hitung panjang string
int hitungPanjang(const char teks[]) {
    int len = 0;
    while (teks[len] != '\0') {
        len++;
    }
    return len;
}

// Fungsi manual penyandian
void enkripsiAlien(const char teks[]) {
    char hasil[100];
    int len = hitungPanjang(teks);

    if (len == 0) return;

    // Huruf pertama tidak berubah
    hasil[0] = teks[0];

    for (int i = 1; i < len; i++) {
        int valSekarang = teks[i] - 'A' + 1;
        int valSebelumnya = teks[i - 1] - 'A' + 1;

        int valBaru = valSekarang + valSebelumnya;
        if (valBaru > 26) {
            valBaru -= 26;
        }

        hasil[i] = (char)(valBaru + 'A' - 1);
    }
    hasil[len] = '\0'; // Penanda akhir string

    std::cout << "Pesan Ter-sandi: " << hasil << "\n";
}

int main() {
    char teks[100];
    std::cout << "Masukkan teks (HURUF KAPITAL): ";
    std::cin >> teks;

    enkripsiAlien(teks);

    return 0;
}