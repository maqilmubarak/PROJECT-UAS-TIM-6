#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "adminfunction.h"
#include "../fileio/fileio.h"
#include "../utils/utils.h"

void adminListItems(){
    printf("\nDAFTAR ALAT\n");
    if(countItem == 0) {
        printf("Alat belum tersedia.\n");
        return;
   }

   printf("ID | NAMA | MERK | MODEL | TAHUN | JUMLAH\n");
   for(int i = 0; i < countItem; i++) {
    printf("%u | %s | %s | %s | %u | %u\n",
    items[i].idAlat, items[i].name, items[i].merek, items[i].model, items[i].productionYear, items[i].quantity);

   }
}

void adminAddItems() {
    Item alat;
    char buf[256];

    alat.idAlat = nextItemId();

    printf("Nama alat: ");
    safeGets(buf, sizeof(buf));
    strncpy(alat.name, buf, sizeof(alat.name) - 1);
    alat.name[sizeof(alat.name) - 1] = '\0';

    printf("Merek: ");
    safeGets(buf, sizeof(buf));
    strncpy(alat.merek, buf, sizeof(alat.merek) - 1);
    alat.merek[sizeof(alat.merek) - 1] = '\0';

    printf("Model: ");
    safeGets(buf, sizeof(buf));
    strncpy(alat.model, buf, sizeof(alat.model) - 1);
    alat.model[sizeof(alat.model) - 1] = '\0';

    printf("Tahun: ");
    safeGets(buf, sizeof(buf));
    alat.productionYear = (uint32_t) atoi(buf);

    printf("Jumlah unit: ");
    safeGets(buf, sizeof(buf));
    alat.quantity = (uint32_t) atoi(buf);

    if (addItem(&alat)) {
        printf("Item berhasil ditambahkan. ID = %u\n", alat.idAlat);
    } else {
        printf("Gagal menambah item.\n");
    }
}

void adminEditItems() {
    char buf[64];
    printf("Masukkan ID item yang ingin diedit: ");
    safeGets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf);

    Item *alat = findItemById(id);
    if (!alat) {
        printf("ID tidak ditemukan.\n");
        return;
    }

    printf("Kosongkan input untuk tidak mengubah.\n");

    printf("Nama (%s): ", alat->name);
    safeGets(buf, sizeof(buf));
    if(strlen(buf)) {
        strncpy(alat->name, buf, sizeof(alat->name)-1);
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
    if (strlen(buf)) alat->productionYear = (uint32_t)atoi(buf);

    printf("Jumlah (%u): ", alat->quantity);
    safeGets(buf, sizeof(buf));
    if (strlen(buf)) alat->quantity = (uint32_t)atoi(buf);

    if (updateItem(alat)) 
        printf("Item berhasil diupdate.\n");
    else 
        printf("Gagal update item.\n");
}


void adminDeleteItems() {
    char buf[64];

    printf("Masukkan ID item yang ingin dihapus: ");
    safeGets(buf, sizeof(buf));

    uint32_t id = (uint32_t)atoi(buf);

    if(deleteItem(id)) {
        printf("Item dan peminjaman terkait dihapus.\n");
    } else {
        printf("Hapus item gagal. ID tidak ditemukan.\n");
    }
}

void adminListLoans(){
    loadLoans();
    printf("=== Daftar semua peminjaman alat ===\n");
    printf("============================================================\n");
    printf("| %-15s | %-8s | %-8s | \n","Username","ID Alat", "jumlah\n");
    printf("=============================================================\n");

    if (countLoan == 0){
        printf("| Tidak ada data peminjaman.                            |\n");
    }else{
        for(int i = 0; i < countLoan; i++){
            printf("| %-15s | %-8u | %-8u |\n", loans[i].username, loans[i].itemId, loans[i].quantity);
        }
    }
    printf("=================================================================\n");
}

void adminCreateAccount() {
    char username[64], password[64], role[16];

    // Input username
    printf("Masukkan username baru: ");
    safe_gets(username, sizeof(username));

    if (strlen(username) == 0) {
        printf("Username tidak boleh kosong.\n");
        return;
    }

    // Cek apakah username sudah ada
    if (find_account(username)) {
        printf("Username sudah ada.\n");
        return;
    }

    // Input password
    printf("Masukkan password: ");
    safe_gets(password, sizeof(password));

    // Input role
    printf("Role (admin/user): ");
    safe_gets(role, sizeof(role));

    // Validasi role
    if (strcmp(role, "admin") != 0 && strcmp(role, "user") != 0) {
        printf("Role tidak valid.\n");
        return;
    }

    // Buat akun
    if (add_account(username, password, role)) {
        printf("Akun dibuat.\n");
    } else {
        printf("Gagal membuat akun.\n");
    }
}

void adminMenu(const char *username) {
    char choice[8];

    while (1) {
        printf("\n=== MENU ADMIN (%s)===\n", username);
        printf("1. Lihat daftar alat\n");
        printf("2. Tambah alat\n");
        printf("3. Edit alat\n");
        printf("4. Hapus alat\n");
        printf("5. Lihat semua peminjaman\n");
        printf("6. Buat akun baru\n");
        printf("7. Logout\n");
        printf("Pilih: ");

        safeGets(choice, sizeof(choice));

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
            printf("Logout\n");
            break;
        }
        else {
            printf("Pilihan tidak valid!\n");
        }
    }
}
