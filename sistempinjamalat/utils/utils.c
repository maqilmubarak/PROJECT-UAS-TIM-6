#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void safeGets(char *buf, size_t n) {
    if (fgets(buf, n, stdin)) {
        size_t len = strlen(buf);

        // hapus newline di akhir string
        while (len > 0 && (buf[len - 1] == '\n')) {
            buf[len - 1] = '\0';
            len--;
        }
    } else {
        buf[0] = '\0';
    }
}

void pauseAndClear() {
    char buf[8];
    printf("\nTekan Enter untuk melanjutkan...");
    
    safeGets(buf, sizeof(buf)); 

    #if defined(_WIN32)
        system("cls");
    #else
        system("clear");
    #endif
}

void clearScreen() {
    #if defined(_WIN32) 
        system("cls");
    #else
        system("clear");
    #endif
}