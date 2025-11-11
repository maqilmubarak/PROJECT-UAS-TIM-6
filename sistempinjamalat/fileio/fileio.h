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
}

// Deklarasi Global Variabel
extern Account accounts[MAX_ACCOUNTS];
extern int account_count;

extern Item items[MAX_ITEMS];
extern int item_count;

extern Loan loans[MAX_LOANS];
extern int loan_count;

// Save and Load Function
void load_accounts();
void save_accounts();

void load_items();
void save_items();

void load_loans();
void save_loans();


#endif