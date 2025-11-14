#include <stdio.h>
#include <string.h>
#include "login.h"
#include "../fileio/fileio.h"

Account* authenticateCli(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Penggunaan: %s <username> <password>\n", argv[0]);
        return NULL;
    }

    char *username = argv[1];
    char *password = argv[2];
    Account* foundAccount = NULL;

    foundAccount = findAccount(username);

    if(foundAccount != NULL) {
        if (strcmp(password, foundAccount->password) == 0) {
            printf("\nLogin berhasil! Selamat datang, %s.\n", foundAccount->username);
            return foundAccount;
        }
    }
    printf("\nLogin Gagal! Username atau passowrd salah.\n");
    return NULL;
}


