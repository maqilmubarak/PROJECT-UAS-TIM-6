#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char kata[128][64];
    int totalKarakter;
} Kosakata;

void alphabetOnlyCoy(char *src, char *dest){
    int i = 0;
    for(int j = 0; src[j] != "\0"; j++){
        if(isalpha(src[j]) || src[j] == '\''){
            dest[i++] = word[i];     
        }
    }
    dest[j] = '\0';
}

int main(){
    FILE *fptr = fopen("lirik.txt", "r");

    if(fptr == NULL){
        printf("[!] Tidak dapat membuka file lirik.txt\n");
        return EXIT_FAILURE;
    }



    return EXIT_SUCCESS;
}