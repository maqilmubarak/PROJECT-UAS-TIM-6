#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define WHITE "\033[37m"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "userfunction.h"
#include "../fileio/fileio.h"
#include "../utils/utils.h"

void userListAvailable() {
    printf("\n" CYAN BOLD "=== DAFTAR ALAT LAB YANG TERSEDIA ===" RESET "\n");

    bool found = false;

    printf(YELLOW BOLD"+--------+----------------------+----------------------+----------------------+--------+--------+\n" RESET);
    printf(YELLOW BOLD"| ID     | Nama                 | Merek                | Model                | Tahun  | Stok   |\n" RESET);
    printf(YELLOW BOLD"+--------+----------------------+----------------------+----------------------+--------+--------+\n" RESET);

    for (int i = 0; i < countItem; i++) {
        if (items[i].quantity > 0) {

            printf("| %-6d | %-20s | %-20s | %-20s | %-6d | %-6d |\n",
                items[i].idAlat,
                items[i].name,
                items[i].merek,
                items[i].model,
                items[i].productionYear,
                items[i].quantity
            );

            found = true;
        }
    }

    printf(YELLOW "+--------+----------------------+----------------------+----------------------+--------+--------+\n" RESET);

    if (!found) {
        printf(RED "[!] Tidak ada alat tersedia.\n" RESET);
    }
    pauseAndClear();
}

void userSearchItems(const char *username) {
    char query[128];

    printf(CYAN BOLD "\n=== CARI ALAT TERSEDIA ===\n" RESET);
    printf("Masukkan nama alat yang ingin dicari: ");
    safeGets(query, sizeof(query));

    if (strlen(query) == 0) {
        printf(RED "Query pencarian tidak boleh kosong.\n" RESET);
        return;
    }

    printf(CYAN BOLD "\n--- HASIL PENCARIAN TERSEDIA ---\n" RESET);

    // Header tabel
    printf(YELLOW BOLD "+--------+----------------------+----------------------+----------------------+--------+--------+\n" RESET);
    printf(YELLOW BOLD "| ID     | Nama                 | Merek                | Model                | Tahun  | Stok   |\n" RESET);
    printf(YELLOW BOLD "+--------+----------------------+----------------------+----------------------+--------+--------+\n" RESET);

    int found = 0;

    for (int i = 0; i < countItem; i++) {

        // Harus quantity > 0 dan nama sesuai
        if (items[i].quantity > 0 && strstr(items[i].name, query) != NULL) {

            printf("| %-6u | %-20s | %-20s | %-20s | %-6u | %-6u |\n",
                items[i].idAlat,
                items[i].name,
                items[i].merek,
                items[i].model,
                items[i].productionYear,
                items[i].quantity
            );

            found = 1;
        }
    }

    printf(YELLOW BOLD "+--------+----------------------+----------------------+----------------------+--------+--------+\n" RESET);

    if (!found) {
        printf(RED "Tidak ada alat tersedia yang ditemukan dengan nama '%s'.\n" RESET, query);
    }
}



void userBorrow(const char *username) {
    char buf[64];

    printf(CYAN "Masukkan ID alat yang ingin dipinjam: " RESET);
    safeGets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf);

    Item *alat = findItemById(id);
    if (alat == NULL) {
        printf(RED "[!] ID tidak ditemukan.\n" RESET);
        return;
    }

    printf("Jumlah tersedia: " GREEN "%u" RESET ". Masukkan jumlah: ", alat->quantity);
    safeGets(buf, sizeof(buf));
    uint32_t jumlahPinjam = (uint32_t)atoi(buf);

    if (jumlahPinjam == 0) {
        printf(RED "[!] Jumlah harus > 0.\n" RESET);
        return;
    }
    if (jumlahPinjam > alat->quantity) {
        printf(RED "[!] Stok tidak mencukupi.\n" RESET);
        return;
    }

    if (!addOrUpdateLoans(username, id, jumlahPinjam)) {
        printf(RED "[!] Gagal meminjam (kapasitas penuh?).\n" RESET);
        return;
    }

    alat->quantity -= jumlahPinjam;
    saveItems();

    printf(GREEN "[+] Berhasil meminjam %u unit '%s'.\n" RESET, jumlahPinjam, alat->name);
}

void userListBorrowed(const char *username) {
    
    printf("\n" CYAN BOLD "=== DAFTAR ALAT YANG ANDA PINJAM ===" RESET "\n");
    int found = 0;

    for (int i = 0; i < countLoan; i++) {
        if (strcmp(loans[i].username, username) == 0) {
            Item *alat = findItemById(loans[i].itemId);

            printf(GREEN "%u" RESET " | " WHITE "%s" RESET " | Jumlah: " YELLOW "%u" RESET "\n",
                   loans[i].itemId,
                   alat ? alat->name : RED "(Item telah dihapus)" RESET,
                   loans[i].quantity);

            found = 1;
        }
    }

    if (found == false) {
        printf(RED "[!] Anda belum meminjam alat.\n" RESET);
    }
}

void userReturn(const char *username) {
    char buf[64];

    printf(CYAN "Masukkan ID alat yang ingin dikembalikan: " RESET);
    safeGets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf);

    int itemIndex = findLoansIndex(username, id);
    if (itemIndex == -1) {
        printf(RED "[!] Anda tidak meminjam alat dengan ID tersebut.\n" RESET);
        return;
    }

    printf("Anda meminjam " YELLOW "%u" RESET " unit. Masukkan jumlah yang dikembalikan: ",
           loans[itemIndex].quantity);
    safeGets(buf, sizeof(buf));
    uint32_t jumlahKembali = (uint32_t)atoi(buf);

    if (jumlahKembali == 0 || jumlahKembali > loans[itemIndex].quantity) {
        printf(RED "[!] Jumlah tidak valid.\n" RESET);
        return;
    }

    Item *alat = findItemById(id);
    if (alat != NULL) {
        alat->quantity += jumlahKembali;
        saveItems();
    }

    removeOrDecreaseLoan(username, id, jumlahKembali);

    printf(GREEN "[+] Berhasil mengembalikan %u unit.\n" RESET, jumlahKembali);
}

void userMenu(const char *username) {
    char choice[8];
    while (1) {
        printf("\n" MAGENTA BOLD "=========== MENU USER (%s) ===========" RESET "\n", username);
        printf(GREEN "1." RESET " Lihat alat tersedia\n");
        printf(GREEN "2." RESET " Pinjam alat\n");
        printf(GREEN "3." RESET " Lihat alat yang dipinjam\n");
        printf(GREEN "4." RESET " Kembalikan alat\n");
        printf(GREEN "5." RESET " Cari alat tersedia\n");
        printf(GREEN "6." RESET " Logout\n");

        printf(YELLOW "Pilih: " RESET);
        safeGets(choice, sizeof(choice));

        if (strcmp(choice, "1") == 0){   
            clearScreen();
            userListAvailable();
        }
        else if (strcmp(choice, "2") == 0){
            clearScreen();
            userBorrow(username);
        }
        else if (strcmp(choice, "3") == 0){
            clearScreen();
            userListBorrowed(username);
        }
        else if (strcmp(choice, "4") == 0){
            clearScreen();
            userReturn(username);
        }
        else if (strcmp(choice, "5") == 0){
            clearScreen();
            userSearchItems(username);
        }
        else if (strcmp(choice, "6") == 0) {
            clearScreen();
            printf("Logout.\n");
            break;
        } else
            printf(RED "[!] Pilihan tidak valid.\n" RESET);
    }
}


