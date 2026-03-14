#include <stdio.h>
#include <string.h>

// Struktur data sederhana
typedef struct {
    char nama[50];
    float saldo;
} Mahasiswa;

typedef struct {
    char nama_menu[30];
    float harga;
} Menu;

int main() {
    // Simulasi data mahasiswa (Contoh: Data kamu)
    Mahasiswa mhs = {"Julia", 50000.0}; 
    Menu menu_pilihan = {"Nasi Ayam Penyet", 15000.0};
    int jumlah;

    printf("--- Sistem Pre-Order Kafetaria IT Del ---\n");
    printf("Halo, %s! Saldo Anda saat ini: Rp%.2f\n", mhs.nama, mhs.saldo);
    printf("Menu: %s | Harga: Rp%.2f\n", menu_pilihan.nama_menu, menu_pilihan.harga);
    
    printf("Masukkan jumlah porsi: ");
    scanf("%d", &jumlah);

    float total_biaya = menu_pilihan.harga * jumlah;

    printf("\n--- Validasi Transaksi ---\n");
    printf("Total yang harus dibayar: Rp%.2f\n", total_biaya);

    // Logika Validasi Saldo
    if (mhs.saldo >= total_biaya) {
        mhs.saldo -= total_biaya; // Potong saldo
        printf("Status: PEMBAYARAN BERHASIL!\n");
        printf("Sisa saldo Anda: Rp%.2f\n", mhs.saldo);
        printf("Silakan ambil pesanan Anda pada jam istirahat.\n");
    } else {
        printf("Status: TRANSAKSI GAGAL!\n");
        printf("Maaf, saldo kartu RFID Anda tidak mencukupi. Kurang: Rp%.2f\n", total_biaya - mhs.saldo);
    }

    return 0;
}