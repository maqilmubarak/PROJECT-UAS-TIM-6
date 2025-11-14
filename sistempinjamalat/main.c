#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileio/fileio.h"
#include "login/login.h"
#include "admin/adminfunction.h"
#include "user/userfunction.h"
#include "utils/utils.h"

int main(int argc, char *argv[]){
    loadAccounts();
    loadItems();
    loadLoans();

    Account *acc = authenticateCli();
    if(acc == NULL){return EXIT_FAILURE;}

    printf("Login Berhasil\n");

    if(strcmp(acc->role, "admin") == 0){ adminMenu(acc->username); }
    else{ userMenu(acc->username); }

    return EXIT_SUCCESS;
}