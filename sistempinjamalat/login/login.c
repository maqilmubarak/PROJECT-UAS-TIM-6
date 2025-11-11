#include <stdio.h>
#include <string.h>
#include "login.h"
#include "fileio.h"
#include "adminfunction.h"
#include "userfunction.h"

int login (char *username, char *password) {
    int i;
    for (i = 0; i < total_user; i++) {
        if (strcmp(daftar_user[i].username, username) == 0 &&
            strcmp(daftar_user[i].password, password) == 0)
            
    }
}