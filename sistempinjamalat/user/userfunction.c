#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "userfunction.h"
#include "../fileio/fileio.h"
#include "../utils/utils.h"

void userListAvailable() {
    printf("\n=== DAFTAR ALAT LAB YANG TERSEDIA ===\n");
    bool found = false;

    for (int i = 0; i < countItem; i++) {
        if (items[i].quantity > 0) {
            printf("%d | %s | %s | %s | %d | %d\n",
                items[i].idAlat,
                items[i].name,
                items[i].merek,
                items[i].model,
                items[i].productionYear,
                items[i].quantity);
            found = true;
        }
    }

    if (found == false) {
        printf("Tidak ada alat tersedia.\n");
    }

}

void userBorrow(const char *username) {
    char buf[64];

    printf("Masukkan ID alat yang ingin dipinjam: ");
    safeGets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf);

    Item *alat = findItemById(id);
    if (alat == NULL) {
        printf("ID tidak ditemukan.\n");
        return;
    }

    printf("Jumlah tersedia: %u. Masukkan jumlah: ", alat->quantity);
    safeGets(buf, sizeof(buf));
    uint32_t jumlahPinjam = (uint32_t)atoi(buf);

    if (jumlahPinjam == 0) {
        printf("Jumlah harus > 0.\n");
        return;
    }
    if (jumlahPinjam > alat->quantity) {
        printf("Stok tidak mencukupi.\n");
        return;
    }

    if (!addOrUpdateLoans(username, id, jumlahPinjam)) {
        printf("Gagal meminjam (kapasitas loans?).\n");
        return;
    }

    alat->quantity -= jumlahPinjam;
    saveItems();

    printf("Berhasil meminjam %u unit '%s'.\n", jumlahPinjam, alat->name);
}

void userListBorrowed(const char *username) {
    
    printf("\n=== DAFTAR ALAT YANG ANDA PINJAM ===\n");
    int found = 0;

    for (int i = 0; i < countLoan; i++) {
        if (strcmp(loans[i].username, username) == 0) {
            Item *alat = findItemById(loans[i].itemId);

            printf("%u | %s | Jumlah: %u\n",
                loans[i].itemId,
                alat ? alat->name : "(Item telah dihapus)",
                loans[i].quantity);

            found = 1;
        }
    }

    if (found == false) {
        printf("Anda belum meminjam alat.\n");
    }
}

void userReturn(const char *username) {
    char buf[64];

    printf("Masukkan ID alat yang ingin dikembalikan: ");
    safeGets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf);

    int itemIndex = findLoansIndex(username, id);
    if (itemIndex == -1) {
        printf("Anda tidak meminjam alat dengan ID tersebut.\n");
        return;
    }

    printf("Anda meminjam %u unit. Masukkan jumlah yang dikembalikan: ",
           loans[itemIndex].quantity);
    safeGets(buf, sizeof(buf));
    uint32_t jumlahKembali = (uint32_t)atoi(buf);

    if (jumlahKembali == 0 || jumlahKembali > loans[itemIndex].quantity) {
        printf("Jumlah tidak valid.\n");
        return;
    }

    Item *alat = findItemById(id);
    if (alat != NULL) {
        alat->quantity += jumlahKembali;
        saveItems();
    }

    removeOrDecreaseLoan(username, id, jumlahKembali);

    printf("Berhasil mengembalikan %u unit.\n", jumlahKembali);
}

void userMenu(const char *username) {
    char choice[8];
    while (1) {
        printf("\n=== MENU USER (%s) ===\n", username);
        printf("1. Lihat alat tersedia\n");
        printf("2. Pinjam alat\n");
        printf("3. Lihat alat yang dipinjam\n");
        printf("4. Kembalikan alat\n");
        printf("5. Logout\n");
        printf("Pilih: ");
        safeGets(choice, sizeof(choice));

        if (strcmp(choice, "1") == 0)
            userListAvailable();
        else if (strcmp(choice, "2") == 0)
            userBorrow(username);
        else if (strcmp(choice, "3") == 0)
            userListBorrowed(username);
        else if (strcmp(choice, "4") == 0)
            userReturn(username);
        else if (strcmp(choice, "5") == 0) {
            printf("Logout.\n");
            break;
        } else
            printf("Pilihan tidak valid.\n");
    }
}


