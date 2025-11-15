#ifndef FILEIO_h
#define FILEIO_h

#include <stdint.h>

#define MAX_ACCOUNTS 128
#define MAX_ITEMS 1024
#define MAX_LOANS 4096
#define LOAN "./data/loan.txt"

typedef struct {
    char username[64];
    char password[64];
    char role[16];      
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
extern int countItem;

extern Loan loans[MAX_LOANS];
extern int countLoan;

// Save and Load Function
void loadAccounts();
void saveAccounts();

void loadItems();
void saveItems();

void loadLoans();
void saveLoans();

// Finding and CRUD Function
Item* findItemById(uint32_t id);
Account* findAccount(const char *username);
uint32_t nextItemId();
int addItem(Item *newItem);
int updateItem(Item *itemUpdate);
int deleteItem(uint32_t idDelete);

// save and load loans Fuction
int findLoansIndex(const char * username, unsigned int itemId);
int addOrUpdateLoans(const char * username, unsigned int itemId, unsigned int quantity);
int removeOrDecreaseLoan(const char *username, uint32_t itemId, uint32_t quantity);

// Utility Function
void trimNewline(char * s);

// Account function
int addAccount(const char* user, const char* pass, const char* role);


#endif
