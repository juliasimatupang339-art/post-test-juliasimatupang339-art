#include <stdio.h>
#include <string.h>

int main() {
    char kode[10];
    float beratButet, beratUcok, totalBerat, ongkosPerKg, totalOngkos;
    int diskonAktif, asuransiAktif;

    while (1) {
        // Input Kode Kota
        scanf("%s", kode);
        
        // Cek jika input adalah END
        if (strcmp(kode, "END") == 0) break;

        // Input Berat Butet
        scanf("%f", &beratButet);

        // Inisialisasi variabel dasar
        ongkosPerKg = 0;
        int luarPulau = 0;

        // Logika Tabel Harga
        if (strcmp(kode, "MDN") == 0) {
            ongkosPerKg = 8000;
        } else if (strcmp(kode, "BLG") == 0) {
            ongkosPerKg = 5000;
        } else if (strcmp(kode, "JKT") == 0) {
            ongkosPerKg = 12000;
            luarPulau = 1;
        } else if (strcmp(kode, "SBY") == 0) {
            ongkosPerKg = 13000;
            luarPulau = 1;
        }

        // Hitung Berat dan Ongkos Dasar
        beratUcok = 1.5 * beratButet;
        totalBerat = beratButet + beratUcok;
        totalOngkos = totalBerat * ongkosPerKg;

        // Logika Promo
        diskonAktif = (totalBerat > 10) ? 1 : 0;
        asuransiAktif = luarPulau;

        if (diskonAktif) {
            totalOngkos = totalOngkos * 0.9; // Potongan 10%
        }

        // Output Struk
        printf("--- Struk Pembayaran ---\n");
        printf("Kota Tujuan: %s\n", kode);
        printf("Berat Paket Butet: %.2f kg\n", beratButet);
        printf("Berat Paket Ucok: %.2f kg\n", beratUcok);
        printf("Total Berat: %.2f kg\n", totalBerat);
        printf("Total Ongkos Kirim: Rp. %.2f\n", totalOngkos);
        
        printf("Promo: ");
        if (diskonAktif && asuransiAktif) printf("Diskon 10%% & Asuransi Gratis\n");
        else if (diskonAktif) printf("Diskon 10%%\n");
        else if (asuransiAktif) printf("Asuransi Gratis\n");
        else printf("-\n");
        printf("------------------------\n\n");
    }

    return 0;
}