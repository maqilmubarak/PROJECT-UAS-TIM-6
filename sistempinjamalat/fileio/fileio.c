#ifndef DATA_h
#define DATA_h

#include <stdint.h>

#define MAX_ACCOUNTS 128
#define MAX_ITEMS 1024
#define MAX_LOANS 4096

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


#endif