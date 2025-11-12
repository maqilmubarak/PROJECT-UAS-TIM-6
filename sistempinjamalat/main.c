#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userFunction.h"
#include "data.h"
#include "utils.h"

// === USER FUNCTIONS ===

static void user_list_available() {
    printf("\n=== ALAT TERSEDIA ===\n");
    int found = 0;
    for (int i = 0; i < item_count; i++) {
        if (items[i].qty > 0) {
            printf("%u | %s | %s | %s | %u | %u\n",
                items[i].id,
                items[i].name,
                items[i].brand,
                items[i].model,
                items[i].year,
                items[i].qty);
            found = 1;
        }
    }
    if (!found)
        printf("Tidak ada alat tersedia.\n");
}

static void user_borrow(const char *username) {
    char buf[64];
    printf("Masukkan ID alat yang ingin dipinjam: ");
    safe_gets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf);

    Item *it = find_item_by_id(id);
    if (!it) {
        printf("ID tidak ditemukan.\n");
        return;
    }

    printf("Jumlah tersedia: %u. Masukkan jumlah: ", it->qty);
    safe_gets(buf, sizeof(buf));
    uint32_t q = (uint32_t)atoi(buf);

    if (q == 0) {
        printf("Jumlah harus > 0.\n");
        return;
    }

    if (q > it->qty) {
        printf("Stok tidak mencukupi.\n");
        return;
    }

    if (!add_or_update_loan(username, id, q)) {
        printf("Gagal meminjam (kapasitas loans?).\n");
        return;
    }

    it->qty -= q;
    save_items();
    printf("Berhasil meminjam %u unit '%s'.\n", q, it->name);
}

static void user_list_borrowed(const char *username) {
    printf("\n=== DAFTAR ALAT YANG ANDA PINJAM ===\n");
    int found = 0;
    for (int i = 0; i < loan_count; i++) {
        if (strcmp(loans[i].username, username) == 0) {
            Item *it = find_item_by_id(loans[i].itemid);
            printf("ID=%u | %s | Jumlah=%u\n",
                loans[i].itemid,
                it ? it->name : "(dihapus)",
                loans[i].qty);
            found = 1;
        }
    }
    if (!found)
        printf("Anda belum meminjam alat.\n");
}

static void user_return(const char *username) {
    char buf[64];
    printf("Masukkan ID alat yang ingin dikembalikan: ");
    safe_gets(buf, sizeof(buf));
    uint32_t id = (uint32_t)atoi(buf);

    int idx = find_loan_index(username, id);
    if (idx == -1) {
        printf("Anda tidak meminjam item ini.\n");
        return;
    }

    printf("Anda meminjam %u unit. Masukkan jumlah yang dikembalikan: ", loans[idx].qty);
    safe_gets(buf, sizeof(buf));
    uint32_t q = (uint32_t)atoi(buf);

    if (q == 0 || q > loans[idx].qty) {
        printf("Jumlah tidak valid.\n");
        return;
    }

    // restore stock
    Item *it = find_item_by_id(id);
    if (it) {
        it->qty += q;
        save_items();
    }

    remove_or_decrease_loan(username, id, q);
    printf("Berhasil mengembalikan %u unit.\n", q);
}

void user_menu(const char *username) {
    char choice[8];
    while (1) {
        printf("\n=== MENU USER (%s) ===\n", username);
        printf("1. Lihat alat tersedia\n");
        printf("2. Pinjam alat\n");
        printf("3. Lihat alat yang dipinjam\n");
        printf("4. Kembalikan alat\n");
        printf("5. Logout\n");
        printf("Pilih: ");
        safe_gets(choice, sizeof(choice));

        if (strcmp(choice, "1") == 0)
            user_list_available();
        else if (strcmp(choice, "2") == 0)
            user_borrow(username);
        else if (strcmp(choice, "3") == 0)
            user_list_borrowed(username);
        else if (strcmp(choice, "4") == 0)
            user_return(username);
        else if (strcmp(choice, "5") == 0) {
            printf("Logout.\n");
            break;
        } else
            printf("Pilihan tidak valid.\n");
    }
}
