#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "adminfunction.h"
#include "../fileio/fileio.h"
#include "../utils/utils.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define WHITE "\033[37m"

//menampilkan daftar alat
void adminListItems(){ //fungsi untuk menampilkan semua alat
    printf("\n" CYAN BOLD "=========== DAFTAR ALAT ===========" RESET "\n");
    if(countItem == 0) {
        printf(RED "Alat belum tersedia.\n" RESET);
        return;
   }

    printf(WHITE BOLD"+---------------------------------------------------------------------------------------+\n");
    printf(YELLOW BOLD "| %-5s | %-20s | %-15s | %-15s | %-6s | %-6s    |\n" RESET,
        "ID", "Nama", "Merek", "Model", "Tahun", "Jumlah");
    printf(WHITE BOLD "+---------------------------------------------------------------------------------------+\n");

    for(int i = 0; i < countItem; i++) {
        printf("| %-5u | %-20s | %-15s | %-15s | %-6u | %-6u    |\n",
            items[i].idAlat,
            items[i].name,
            items[i].merek,
            items[i].model,
            items[i].productionYear,
            items[i].quantity
        );
    }
    printf("+---------------------------------------------------------------------------------------+\n");

}

//menambahkan alat
void adminAddItems() { //fungsi untuk menambah alat baru
    Item alat; //struct untuk alat data baru
    char buf[256]; //buffer input

    alat.idAlat = nextItemId(); //ambil id baru otomatis

    printf("\n" CYAN BOLD "=========== TAMBAH ALAT ===========" RESET "\n");

    printf("Nama alat       : ");
    safeGets(buf, sizeof(buf));
    strncpy(alat.name, buf, sizeof(alat.name) - 1); //copy ke struct
    alat.name[sizeof(alat.name) - 1] = '\0';

    printf("Merek           : ");
    safeGets(buf, sizeof(buf));
    strncpy(alat.merek, buf, sizeof(alat.merek) - 1);
    alat.merek[sizeof(alat.merek) - 1] = '\0';

    printf("Model           : ");
    safeGets(buf, sizeof(buf));
    strncpy(alat.model, buf, sizeof(alat.model) - 1);
    alat.model[sizeof(alat.model) - 1] = '\0';

    printf("Tahun           : ");
    safeGets(buf, sizeof(buf));
    alat.productionYear = (uint32_t) atoi(buf); //konversi string ke angka

    printf("Jumlah unit     : ");
    safeGets(buf, sizeof(buf));
    alat.quantity = (uint32_t) atoi(buf);

    if (addItem(&alat)) { //simpan alat
        printf(GREEN "[+] Item berhasil ditambahkan. ID = %u\n" RESET, alat.idAlat);
    } else {
        printf(RED "Gagal menambah item.\n"RESET);
    }
}
//mengedit alat
void adminEditItems() { //fungsi untuk edit alat
    char buf[64]; //buffer untuk menampung input sementara
    printf("\n" CYAN BOLD "=========== EDIT ALAT ===========" RESET "\n");
    printf("Masukkan ID item yang ingin diedit: ");
    safeGets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf); //konversi ke angka

    Item *alat = findItemById(id); //cari item berdasarkan ID
    if (!alat) { 
        printf(RED "[!] ID tidak ditemukan.\n" RESET);
        return;
    }

    printf(MAGENTA "Kosongkan input untuk tidak mengubah.\n" RESET);

    printf("Nama (%s): ", alat->name); //tampilkan nilai lama
    safeGets(buf, sizeof(buf)); //membaca input nama baru
    if(strlen(buf)) { //mengecek apakah user memasukkan sesuatu
        strncpy(alat->name, buf, sizeof(alat->name)-1); //menyalin nama baru ke struktur item
        alat->name[sizeof(alat->name)-1] = '\0';
    }

    printf("Merek(%s): ", alat->merek);
    safeGets(buf, sizeof(buf));
    if(strlen(buf)) {
        strncpy(alat->merek, buf, sizeof(alat->merek)-1);
        alat->merek[sizeof(alat->merek)-1] = '\0';
    }

    printf("Model (%s): ", alat->model);
    safeGets(buf, sizeof(buf));
    if(strlen(buf)) {
        strncpy(alat->model, buf, sizeof(alat->model)-1);
        alat->model[sizeof(alat->model)-1] = '\0';
    }

    printf("Tahun (%u): ", alat->productionYear);
    safeGets(buf, sizeof(buf));
    if (strlen(buf)) alat->productionYear = (uint32_t)atoi(buf); //mengubah input menjadi angka jika tidak kosong

    printf("Jumlah (%u): ", alat->quantity);
    safeGets(buf, sizeof(buf));
    if (strlen(buf)) alat->quantity = (uint32_t)atoi(buf); //mengganti jumlah

    if (updateItem(alat)) //panggil fungsi untuk menyimpan perubahan item
        printf(GREEN "[+] Item berhasil diupdate.\n" RESET);
    else 
        printf(RED "[!] Gagal update item.\n" RESET);
}

//menghapus alat
void adminDeleteItems() { //fungsi hapus alat
    char buf[64];

    printf("\n" CYAN BOLD "=========== HAPUS ALAT ===========" RESET "\n");
    printf("Masukkan ID item yang ingin dihapus: "); 
    safeGets(buf, sizeof(buf));

    uint32_t id = (uint32_t)atoi(buf); //konversi ke angka

    if(deleteItem(id)) { //hapus alat
        printf(GREEN "[+] Item dan peminjaman terkait dihapus.\n" RESET);
    } else {
        printf(GREEN "[!] Hapus item gagal. ID tidak ditemukan.\n" RESET);
    }
}

//menampilkan semua peminjaman
void adminListLoans() { // fungsi menampilkan semua peminjaman
    loadLoans(); // muat data peminjaman

    printf("\n" CYAN BOLD "=== Daftar semua peminjaman alat ===" RESET "\n");
    printf(BLUE "=================================================================\n" RESET);

    // Header tabel berwarna
    printf(YELLOW BOLD "| %-15s | %-8s | %-8s |\n" RESET,
           "Username", "ID Alat", "Jumlah");

    printf(BLUE "=================================================================\n" RESET);

    if (countLoan == 0) {
        printf(RED "| %-61s |\n" RESET, "[!] Tidak ada data peminjaman.");
    } else {
        for (int i = 0; i < countLoan; i++) {
            printf(WHITE BOLD "| %-15s | %-8u | %-8u |\n" RESET,
                   loans[i].username,
                   loans[i].itemId,
                   loans[i].quantity);
        }
    }

    printf(BLUE "=================================================================\n" RESET);
}



//membuat akun
void adminCreateAccount() { //fungsi untuk membuat akun
    char username[64], password[64], role[16];

    printf("Masukkan username baru: ");
    safeGets(username, sizeof(username));

    if (strlen(username) == 0) {
        printf("Username tidak boleh kosong.\n");
        return;
    }

    if(findAccount(username)) { //username tidak boleh duplikat
        printf("Username sudah ada.\n");
        return;
    }

    printf("Masukkan password: ");
    safeGets(password, sizeof(password));

    printf("Role (admin/user): ");
    safeGets(role, sizeof(role));

    if (strcmp(role, "admin") != 0 && strcmp(role, "user") != 0) { //validasi role
        printf("Role tidak valid.\n");
        return;
    }

    if (addAccount(username, password, role)) { //simpan akun
        printf("Akun dibuat.\n");
    } else {
        printf("Gagal membuat akun.\n");
    }
}

//menu pada admin
void adminMenu(const char *username) { //fungsi untuk menu utama admin
    char choice[8]; 

    while (1) {
        printf("\n" CYAN BOLD "=========== MENU ADMIN (%s) ===========" RESET "\n", username);
        printf(WHITE BOLD"1. Lihat daftar alat\n"RESET);
        printf(WHITE BOLD"2. Tambah alat\n"RESET);
        printf(WHITE BOLD"3. Edit alat\n"RESET);
        printf(WHITE BOLD"4. Hapus alat\n"RESET);
        printf(WHITE BOLD"5. Lihat semua peminjaman\n"RESET);
        printf(WHITE BOLD"6. Buat akun baru\n"RESET);
        printf(WHITE BOLD"7. Logout\n"RESET);
        printf(WHITE BOLD"Pilih: "RESET);

        safeGets(choice, sizeof(choice)); //input pilihan menu

        if (strcmp(choice, "1") == 0) { 
            adminListItems();
        }
        else if (strcmp(choice, "2") == 0) {
            adminAddItems();
        }
        else if (strcmp(choice, "3") == 0) {
            adminEditItems();
        }
        else if (strcmp(choice, "4") == 0) {
            adminDeleteItems();
        }
        else if (strcmp(choice, "5") == 0) {
            adminListLoans();
        }
        else if (strcmp(choice, "6") == 0) {
            adminCreateAccount();
        }
        else if (strcmp(choice, "7") == 0) {
            printf(WHITE BOLD "GOOD BYE\n");
            break;
        }
        else {
            printf(RED "[!] Pilihan tidak valid!\n" RESET);
        }
    }
}
