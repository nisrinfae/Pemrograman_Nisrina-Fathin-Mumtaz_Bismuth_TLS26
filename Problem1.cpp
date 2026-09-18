#include <iostream>

void simulasikanAstronot(int n, int k) {
    int astronot[1000];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int sisa = n;
    int pos = 0; // Mulai dari astronot nomor 1 (indeks 0)

    std::cout << "\nUrutan Eliminasi:\n";
    while (sisa > 1) {
        // Melangkah (K - 1) kali dari posisi acuan saat ini
        pos = (pos + k - 1) % sisa;
        int nomorDieliminasi = astronot[pos];

        std::cout << "Astronot tereliminasi: " << nomorDieliminasi << "\n";

        // Hapus elemen dari array
        for (int i = pos; i < sisa - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        sisa--;

        // Update K berdasarkan ganjil/genap
        if (nomorDieliminasi % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }

        if (k < 2) {
            k = 2;
        }

        // Catatan: Setelah array digeser ke kiri, indeks `pos` secara otomatis 
        // sudah menunjuk ke astronot tepat setelah astronot yang baru dieliminasi.
    }

    std::cout << "\nAstronot terakhir yang bertahan: " << astronot[0] << "\n";
}

int main() {
    int n, k;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai awal K: ";
    std::cin >> k;

    simulasikanAstronot(n, k);

    return 0;
}