#include <stdio.h>
#include <string.h>
#include "login.h"

Account* find_account(const char* username) {
    for(int i =0; i < account_count; i++) {
        if (strcmp(username, accounts[i], username) == 0) {
            return &accounts[i];
        }
    }
    return NULL;
}
