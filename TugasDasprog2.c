#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h> // Untuk isdigit()

// Fungsi membersihkan layar
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void cetakMenuUtama() {
    printf("####################################################################################\n");
    printf("#################################### Menu Utama ####################################\n");
    printf("####################################################################################\n");
    printf("====  >1. Mencari akar-akar real persamaan kuadrat                              ====\n");
    printf("====  >2. Menampilkan deret bilangan Fibonacci                                  ====\n");
    printf("====  >3. Menampilkan nilai faktorial N                                         ====\n");
    printf("====  >4. Menghitung nilai rata-rata dari n buah bilangan                       ====\n");
    printf("====  >5. Konversi nilai angka ke nilai huruf                                   ====\n");
    printf("====  >6. Konversi suhu                                                         ====\n");
    printf("====  >7. Konversi nilai detik ke jam, menit, dan detik                         ====\n");
    printf("====  >8. Menentukan apakah tahun kabisat atau bukan                            ====\n");
    printf("====  >9. Menentukan apakah bilangan adalah bilangan prima atau bukan           ====\n");
    printf("====  >10. Konversi bilangan desimal ke notasi biner                            ====\n");
    printf("====  >0. Keluar                                                                ====\n");
    printf("####################################################################################\n");
    printf("####################################################################################\n");
}

// Fungsi untuk mencari akar-akar real persamaan kuadrat
void cariAkarKuadrat() {
    double a, b, c;
    double discriminant, x1, x2;

    // Meminta pengguna memasukkan koefisien a, b, dan c
    printf("Masukkan koefisien a: ");
    scanf("%lf", &a);
    printf("Masukkan koefisien b: ");
    scanf("%lf", &b);
    printf("Masukkan koefisien c: ");
    scanf("%lf", &c);

    // Menghitung diskriminan
    discriminant = b * b - 4 * a * c;

    // Memeriksa apakah diskriminan non-negatif
    if (discriminant < 0) {
        printf("Akar-akar imajiner, tidak ada solusi real.\n");
    } else if (discriminant == 0) {
        // Satu akar real
        x1 = -b / (2 * a);
        printf("Akar tunggal: x1 = %.2lf\n", x1);
    } else {
        // Dua akar real
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Akar pertama: x1 = %.2lf\n", x1);
        printf("Akar kedua: x2 = %.2lf\n", x2);
    }
}

// Fungsi untuk menampilkan deret bilangan Fibonacci hingga batas tertentu
void tampilkanFibonacci() {
    int n, prev = 1, current = 1, next;

    printf("Masukkan jumlah angka dalam deret Fibonacci: ");
    scanf("%d", &n);

    printf("Deret Fibonacci: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", prev);
        next = prev + current;
        prev = current;
        current = next;
    }
    printf("\n");
}

// Fungsi untuk menghitung nilai faktorial N
int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

// Fungsi untuk menampilkan nilai faktorial N
void tampilkanFaktorial() {
    int n;

    printf("Masukkan nilai N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Input tidak valid. Nilai N harus non-negatif.\n");
    } else {
        int hasil = faktorial(n);

        printf("%d! = %d\n", n, hasil);
    }
}

// Fungsi untuk menghitung rata-rata dari n buah bilangan
void hitungRataRata() {
    int n;
    double bilangan, total = 0;

    printf("Masukkan jumlah bilangan yang akan dihitung rata-ratanya: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input tidak valid. Jumlah bilangan harus positif.\n");
    } else {
        for (int i = 1; i <= n; i++) {
            printf("Masukkan bilangan ke-%d: ", i);
            scanf("%lf", &bilangan);
            total += bilangan;
        }

        double rataRata = total / n;
        printf("Rata-rata: %.2lf\n", rataRata);
    }
}

// Fungsi untuk konversi nilai angka ke nilai huruf
void konversiNilaiAngka() {
    int nilai;

    printf("Masukkan nilai angka (0-100): ");
    scanf("%d", &nilai);

    if (nilai < 0 || nilai > 100) {
        printf("Input tidak valid. Nilai angka harus berada dalam rentang 0-100.\n");
    } else {
        if (nilai >= 86 && nilai <= 100) {
            printf("Nilai huruf: A\n");
        } else if (nilai >= 71 && nilai <= 85) {
            printf("Nilai huruf: AB\n");
        } else if (nilai >= 66 && nilai <= 70) {
            printf("Nilai huruf: B\n");
        } else if (nilai >= 61 && nilai <= 65) {
            printf("Nilai huruf: BC\n");
        } else if (nilai >= 56 && nilai <= 60) {
            printf("Nilai huruf: C\n");
        } else if (nilai >= 41 && nilai <= 55) {
            printf("Nilai huruf: D\n");
        } else if (nilai >= 0 && nilai <= 40) {
            printf("Nilai huruf: E\n");
        }
    }
}

// Fungsi untuk konversi suhu
void konversiSuhu() {
    char jenisSuhu;
    double suhu;

    printf("Masukkan jenis suhu (C/R/F/K): ");
    scanf(" %c", &jenisSuhu);

    printf("Masukkan nilai suhu: ");
    scanf("%lf", &suhu);

    double hasilSuhu;

    switch (jenisSuhu) {
        case 'C':
            hasilSuhu = suhu;
            break;
        case 'R':
            hasilSuhu = 4.0 / 5.0 * suhu;
            break;
        case 'F':
            hasilSuhu = 9.0 / 5.0 * suhu + 32;
            break;
        case 'K':
            hasilSuhu = suhu + 273.15;
            break;
        default:
            printf("Jenis suhu tidak valid.\n");
            return;
    }

    printf("%.2lf %c setara dengan %.2lf %c\n", suhu, jenisSuhu, hasilSuhu, jenisSuhu);
}

// Fungsi untuk konversi nilai detik ke jam, menit, dan detik
void konversiDetik() {
    int detik;

    printf("Masukkan jumlah detik: ");
    scanf("%d", &detik);

    if (detik < 0) {
        printf("Input tidak valid. Jumlah detik harus positif.\n");
    } else {
        int jam, menit, sisaDetik;

        jam = detik / 3600;
        sisaDetik = detik % 3600;
        menit = sisaDetik / 60;
        sisaDetik = sisaDetik % 60;

        printf("%d detik setara dengan %d jam, %d menit, %d detik\n", detik, jam, menit, sisaDetik);
    }
}

// Fungsi untuk menentukan apakah tahun adalah tahun kabisat atau bukan
int tahunKabisat(int tahun) {
    if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)) {
        return 1; // Tahun kabisat
    } else {
        return 0; // Bukan tahun kabisat
    }
}

// Fungsi untuk mengecek apakah bilangan adalah bilangan prima
int bilanganPrima(int bilangan) {
    if (bilangan <= 1) {
        return 0; // Bukan bilangan prima
    }
    for (int i = 2; i * i <= bilangan; i++) {
        if (bilangan % i == 0) {
            return 0; // Bukan bilangan prima
        }
    }
    return 1; // Bilangan prima
}

// Fungsi untuk mengkonversi bilangan desimal ke notasi biner
void konversiBiner() {
    int bilangan;

    printf("Masukkan bilangan desimal: ");
    scanf("%d", &bilangan);

    if (bilangan < 0) {
        printf("Input tidak valid. Bilangan desimal harus non-negatif.\n");
    } else {
        printf("%d dalam notasi biner: ", bilangan);

        if (bilangan == 0) {
            printf("0");
        } else {
            int hasil[32];
            int i = 0;

            while (bilangan > 0) {
                hasil[i] = bilangan % 2;
                bilangan = bilangan / 2;
                i++;
            }

            for (int j = i - 1; j >= 0; j--) {
                printf("%d", hasil[j]);
            }
        }

        printf("\n");
    }
}

int main() {
    int pilihan;

    while (1) {
        cetakMenuUtama();
        printf("Pilih program (0-10): >");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 0:
                printf("Terima kasih telah menggunakan program ini.\n");
                return 0;
            case 1:
                cariAkarKuadrat();
                break;
            case 2:
                tampilkanFibonacci();
                break;
            case 3:
                tampilkanFaktorial();
                break;
            case 4:
                hitungRataRata();
                break;
            case 5:
                konversiNilaiAngka();
                break;
            case 6:
                konversiSuhu();
                break;
            case 7:
                konversiDetik();
                break;
            case 8:
                {
                    int tahun;
                    printf("Masukkan tahun: ");
                    scanf("%d", &tahun);
                    if (tahunKabisat(tahun)) {
                        printf("%d adalah tahun kabisat.\n", tahun);
                    } else {
                        printf("%d bukan tahun kabisat.\n", tahun);
                    }
                }
                break;
            case 9:
                {
                    int bilangan;
                    printf("Masukkan bilangan: ");
                    scanf("%d", &bilangan);
                    if (bilanganPrima(bilangan)) {
                        printf("%d adalah bilangan prima.\n", bilangan);
                    } else {
                        printf("%d bukan bilangan prima.\n", bilangan);
                    }
                }
                break;
            case 10:
                konversiBiner();
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih program lain.\n");
                break;
        }

        // Tunggu sampai pengguna menekan Enter sebelum membersihkan layar
        printf("\nTekan Enter untuk melanjutkan...");
        while (getchar() != '\n');
        getchar(); // Menunggu pengguna menekan Enter
        clearScreen(); // Membersihkan layar sekarang
    }

    return 0;
}
