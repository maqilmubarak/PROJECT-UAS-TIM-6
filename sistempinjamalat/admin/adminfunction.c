#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "adminfunction.h"
#include "../fileio/fileio.h"
#include "../utils/utils.h"

void adminListItems() {

}

void adminAddItems() {

}

void adminEditItems() {

}

void adminDeleteItems() {

}

void adminListLoans() {

}

void adminCreateAccount() {

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