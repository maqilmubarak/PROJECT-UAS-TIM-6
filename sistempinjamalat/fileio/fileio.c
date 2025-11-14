#include "fileio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
    FILE *fptr = fopen("./data/account.txt", "r");
    if(!fptr){
        fptr = fopen("./data/account.txt", "w");
        // Default credential
        fprintf(fptr, "admin|admin123|admin\n");
        fclose(fptr);
    }

    fptr = fopen("./data/account.txt", "r");
    if(fptr == NULL){ return; }

    char line[256];
    while(fgets(line, sizeof(line), fptr)){
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
    fclose(fptr);
}

void saveAccounts(){
    FILE *fptr = fopen("./data/account.txt", "w");
    if(fptr == NULL) { return; }
    for(int i = 0; i < countAccount; i++){
        fprintf(fptr, "%s|%s|%s\n", accounts[i].username, accounts[i].password, accounts[i].role);
    }
    fclose(fptr);
}

Account* findAccount(const char* username) {
    for(int i = 0; i < countAccount; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            return &accounts[i];
        }
    }
    return NULL;
}


/* Functions For Items */
void loadItems(){
    countItem = 0;
    FILE *fptr = fopen("./data/items.txt", "r");
    if(!fptr) {
        fptr = fopen("./data/items.txt", "w");
        if (fptr) {
            fclose(fptr); 
        }
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fptr) && countItem < MAX_ITEMS) {
        trimNewline(line);
        if (strlen(line) == 0) continue;

        char *token;
        int i = 0;
        char *parts[6] = {0};

        token = strtok(line, "|");
        while (token && i < 6) {
            parts[i++] = token;
            token = strtok(NULL, "|");
        }

        if (i != 6) continue;  

        items[countItem].idAlat = (uint32_t) strtoul(parts[0], NULL, 10);
        strncpy(items[countItem].name,  parts[1], sizeof(items[0].name) - 1);
        strncpy(items[countItem].merek, parts[2], sizeof(items[0].merek) - 1);
        strncpy(items[countItem].model, parts[3], sizeof(items[0].model) - 1);
        items[countItem].productionYear = (uint32_t) strtoul(parts[4], NULL, 10);
        items[countItem].quantity = (uint32_t) strtoul(parts[5], NULL, 10);

        items[countItem].name[sizeof(items[0].name) - 1] = '\0';
        items[countItem].merek[sizeof(items[0].merek) - 1] = '\0';
        items[countItem].model[sizeof(items[0].model) - 1] = '\0';

        countItem++;
    }

    fclose(fptr);
}

void saveItems(){
    FILE *fptr = fopen("./data/items.txt", "w");
    if(fptr == NULL) {
        printf("[!] Gagal Menyimpan Data");
        return;
    }
    for (int i = 0; i < countItem; i++) {
        fprintf(fptr, "%u|%s|%s|%s|%u|%u\n",
                items[i].idAlat, items[i].name, items[i].merek,
                items[i].model, items[i].productionYear, items[i].quantity);
    }
    fclose(fptr);
}

int addItem(Item *newItem){
    if(countItem >= MAX_ITEMS){ return false;}
    items[countItem] = *newItem;
    countItem++;
    saveItems();
    return true;
}


Item * findItemById(uint32_t id){
    for(int i = 0; i < countItem; i++){
        if(items[i].idAlat == id){
            return &items[i];
        }
    }
    return NULL;
}

uint32_t nextItemId() {
    uint32_t max = 0;
    for (int i = 0; i < countItem; i++){
        if (items[i].idAlat > max){
            max = items[i].idAlat;
        } 
    } 
    return max + 1;
}

void loadLoans(){
    FILE* file = fopen(LOAN, "r");
    if (file == NULL){
        countLoan = 0;
        return;
    }
    while(fscanf(file, "%s %u %u",
                loans[countLoan].username,
                &loans[countLoan].itemId,
                &loans[countLoan].quantity) !=EOF){
        countLoan++;
        if(countLoan >= MAX_LOANS) break;
     }
     fclose(file);
}

void saveLoans(){
    FILE *file = fopen(LOAN, "w");
    if (file == NULL){
        printf("Error tidak dapat menyimpan file %s\n", LOAN);
        return;
    }
    for (int i = 0; i < countLoan; i++){
        fprintf(file, "%s %u %u\n",
                loans[i].username,
                loans[i].itemId,
                loans[i].quantity);
    }
    fclose(file);
}

int findLoansIndex(const char *username, unsigned int itemId){
    for(int i = 0; i < countLoan; i++){
        if(strcmp(loans[i].username, username) == 0 && loans[i].itemId == itemId){
            return i;
        }
    }
    return -1;
} 

int addOrUpdateLoans(const char *username, unsigned int itemId, unsigned int quantity){
    loadLoans();

    int status = -1;
    int index = findLoansIndex(username, itemId);

    if (index >= 0){
        loans[index].quantity += quantity;
        status = 1;
    } else if (countLoan < MAX_LOANS){
        strncpy(loans[countLoan].username, username, sizeof(loans[0].username) - 1);
        loans[countLoan].username[sizeof(loans[0].username) - 1] = '\0';
        loans[countLoan].itemId = itemId;
        loans[countLoan].quantity = quantity;
        countLoan++;
        status = 0;
    } else {
        printf("Error: Data pinjaman penuh.\n");
        status = -1;
    }

    saveLoans();
    return status;
}
 

