#include "./data/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

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
