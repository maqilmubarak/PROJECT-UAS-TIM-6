#include <stdio.h>
#include <string.h>
#include "login.h"

Account* find_account(const char* username) {
    for(int i = 0; i < countAccount; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return &accounts[i];
        }
    }
    return NULL;
}

Account* authenticate_cli() {
    char username[64];
    char password[64];
    Account* foundAccount = NULL;

    printf("=== Login ===");
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

    foundAccount = find_account(username);

    if(foundAccount != NULL) {
        if (strcmp(password, foundAccount->password) == 0) {
            printf("\nLogin berhasil! Selamat datang, %s.\n", foundAccount->username);
            return foundAccount;
        }
    }
    printf("\nLogin Gagal! Username atau passowrd salah.\n");
    return NULL;
}