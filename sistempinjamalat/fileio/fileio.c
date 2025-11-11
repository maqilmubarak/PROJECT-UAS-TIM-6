#include "./fileio/fileio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Account accounts[MAX_ACCOUNTS];
int countAccount = 0;

Item items[MAX_ITEMS];
int item_count = 0;

Loan loans[MAX_LOANS];
int loan_count = 0;

void trimNewline(char * s){
    size_t lenght = strlen(s);
    while(lenght > 0 ){
        char lastChar = s[lenght - 1];

        if(lastChar == '\n'){
            s[lenght - 1] = '\0';
            lenght--;
        } else { break; }
    }
}


/* Functions For Accounts Handling */
void loadAccounts(){
    countAccount = 0;
    FILE *fp = fopen("../data/account.txt", "r");
    if(!fp){
        fp = fopen("account.txt", "w");
        fprintf(fp, "admin|admin123|admin\n");
        fclose(fp);
    }

    fp = fopen("../data/account.txt", "r");
    if(fp == NULL){ printf("[!] Tidak dapat membuka accounts.txt\n"); return; }

    char line[256];
    while(fgets(line, sizeof(line), fp)){
        trimNewline(line);
        if(strlen(line) == 0 ) { continue; }

        char * userSeparator = strchr(line, "|");
        char * passwdSeparator = NULL;

        if(userSeparator != NULL){ passwdSeparator = strchr(userSeparator + 1, "|"); }
        if(userSeparator == NULL || passwdSeparator == NULL){ continue; }

        *userSeparator = '\0';
        *passwdSeparator = '\0';

        // copy line to account[].username and substract 1 for NULL BYTE
        strncpy(account[countAccount].username, line, sizeof(account[0].username) - 1);
        strncpy(account[countAccount].password, userSeparator + 1, sizeof(account[0].password) - 1);
        strncpy(account[countAccount].role, passwdSeparator + 1, sizeof(account[0].role) - 1);
        countAccount++;

        if(countAccount >= MAX_ACCOUNTS){ break; }
    }
    fclose(fp);
}

void saveAccounts(){
    FILE *fp = fopen("../data/account.txt", "w");
    if(fp == NULL) { return; }
    for(int i = 0; i < countAccount; i++){
        fprintf(fp, "%s|%s|%s\n", account[i].username, account[i].password, account[i].role);
    }
    fclose(f);
}