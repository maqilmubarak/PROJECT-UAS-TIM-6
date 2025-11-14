#include <stdio.h>
#include <string.h>
#include "login.h"
#include "fileio.h"

Account* authenticateCli() {
    char username[64];
    char password[64];
    Account* foundAccount = NULL;

    printf("=== Login ===\n");
    printf("Username: ");

    if(!fgets(username, sizeof(username), stdin)) {
        return NULL;
    }
    trimNewline(username);

    printf("Password: ");
    if(!fgets(password, sizeof(password), stdin)) {
        return NULL;
    }
    trimNewline(password);

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

int addAccount(const char* user, const char* pass, const char* role) {

}

