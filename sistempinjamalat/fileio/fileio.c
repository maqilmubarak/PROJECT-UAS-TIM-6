#include "fileio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Account accounts[MAX_ACCOUNTS];
int countAccount = 0;

Item items[MAX_ITEMS];
int countItem = 0;

Loan loans[MAX_LOANS];
int countLoan = 0;

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
    FILE *fp = fopen("./data/account.txt", "r");
    if(!fp){
        fp = fopen("./data/account.txt", "w");
        // Default credential
        fprintf(fp, "admin|admin123|admin\n");
        fclose(fp);
    }

    fp = fopen("./data/account.txt", "r");
    if(fp == NULL){ return; }

    char line[256];
    while(fgets(line, sizeof(line), fp)){
        trimNewline(line);
        if(strlen(line) == 0 ) { continue; }

        char * userSeparator = strchr(line, '|');
        char * passwdSeparator = NULL;

        if(userSeparator != NULL){ passwdSeparator = strchr(userSeparator + 1, '|'); }
        if(userSeparator == NULL || passwdSeparator == NULL){ continue; }

        *userSeparator = '\0';
        *passwdSeparator = '\0';

        // copy line to account[].username and substract 1 for NULL BYTE
        strncpy(accounts[countAccount].username, line, sizeof(accounts[0].username) - 1);
        strncpy(accounts[countAccount].password, userSeparator + 1, sizeof(accounts[0].password) - 1);
        strncpy(accounts[countAccount].role, passwdSeparator + 1, sizeof(accounts[0].role) - 1);
        countAccount++;

        accounts[countAccount].username[sizeof(accounts[0].username) - 1] = '\0';
        accounts[countAccount].password[sizeof(accounts[0].password) - 1] = '\0';
        accounts[countAccount].role[sizeof(accounts[0].role) - 1] = '\0';

        if(countAccount >= MAX_ACCOUNTS){ break; }
    }
    fclose(fp);
}

void saveAccounts(){
    FILE *fp = fopen("./data/account.txt", "w");
    if(fp == NULL) { return; }
    for(int i = 0; i < countAccount; i++){
        fprintf(fp, "%s|%s|%s\n", accounts[i].username, accounts[i].password, accounts[i].role);
    }
    fclose(fp);
}











/* Functions For Items */
void loadItems(){
    
}

void saveItems(){

}


Item * findItemById(uint32_t id){
    for(int i = 0; i < countItem; i++){
        if(items[i].idAlat == id);
        return &items[i];
    }
}

uint32_t nextItemId() {
    uint32_t max = 0;
    for (int i = 0; i < countItem; i++){
        if (items[i].idAlat > max){
            max = items[i].idAlat;
        } 
        return max + 1;
    } 
}