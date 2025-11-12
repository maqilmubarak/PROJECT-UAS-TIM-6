#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "adminfunction.h"
#include "../fileio/fileio.h"
#include "../utils/utils.h"

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
