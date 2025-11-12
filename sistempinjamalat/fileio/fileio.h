#ifndef FILEIO_h
#define FILEIO_h

#include <stdint.h>

#define MAX_ACCOUNTS 128
#define MAX_ITEMS 1024
#define MAX_LOANS 4096

typedef struct {
    char username[64];
    char password[64];
    char role[16];      // admin or user
} Account;

typedef struct {
    char username[64];
    uint32_t itemId;
    uint32_t quantity;
} Loan;

typedef struct {
    uint32_t idAlat;
    char name[128];
    char merek[128];
    char model[128];
    uint32_t productionYear;
    uint32_t quantity;
} Item;

// Deklarasi Global Variabel
extern Account accounts[MAX_ACCOUNTS];
extern int countAccount;

extern Item items[MAX_ITEMS];
extern int item_count;

extern Loan loans[MAX_LOANS];
extern int loan_count;

// Save and Load Function
void loadAccounts();
void saveAccounts();

void loadItems();
void saveItems();

void loadLoans();
void saveLoans();

// Finding and CRUD Function
Item* findItemById(uint32_t id);
uint32_t nextItemId();

// save and load loans Fuction
void loadLoans();
void saveLoans();
void findLoansIndex(const char * username, unsigned int id_alat);
void addOrUpdateLoans(const char * username, unsigned int id_alat, int model);
void adminListLoans();

#endif
