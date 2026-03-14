#include <stdio.h>

int main() {
    int N;
    
    // 1. Membaca jumlah total barang
    if (scanf("%d", &N) != 1) return 0;

    int stok[N];
    int kategori[N];

    // 2. Membaca N baris data (jumlah_stok dan kode_kategori)
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &stok[i], &kategori[i]);
    }

    // 3. Membaca kode kategori yang ingin dihitung totalnya
    int kategoriDicari;
    scanf("%d", &kategoriDicari);

    int totalStok = 0;

    // 4. Perulangan untuk menghitung total stok berdasarkan kategori
    for (int i = 0; i < N; i++) {
        if (kategori[i] == kategoriDicari) {
            totalStok += stok[i];
        }
    }

    // 5. Menampilkan hasil akhir
    printf("%d\n", totalStok);

    return 0;
}