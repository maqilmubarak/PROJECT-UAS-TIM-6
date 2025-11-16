#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char kata[128][64];
    int totalKarakter;
} Kosakata;

int main(){
    FILE *fptr = fopen("lirik.txt", "r");

    if(fptr == NULL){
        printf("[!] Tidak dapat membuka file lirik.txt\n");
        return EXIT_FAILURE;
    }

    

    return EXIT_SUCCESS;
}