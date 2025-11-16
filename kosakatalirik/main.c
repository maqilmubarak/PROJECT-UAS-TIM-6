#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char kata[128][64];
    int totalKata;
} Kosakata;

void alphabetOnlyCoy(char *src, char *dest){
    int i = 0;
    for(int j = 0; src[j] != '\0'; j++){
        if(isalpha(src[j]) || src[j] == '\''){
            dest[i] = tolower(src[i]);
            i++;     
        }
    }
    dest[i] = '\0';
}

int kataSudahDitemukan(Kosakata *listKata, char *kata){
    for(int i = 0; i < listKata->totalKata; i++){
        if(strcmp(listKata->kata[i], kata) == 0){
            return 1;
        }
    }
    return 0;
}


int main(){
    Kosakata kata = {0};
    char baris[128];
    char kataAlphabetOnly[128];

    FILE *fptr = fopen("lirik.txt", "r");

    if(fptr == NULL){
        printf("[!] Tidak dapat membuka file lirik.txt\n");
        return EXIT_FAILURE;
    }

    char *perKata = strtok(baris, " \n");
    while(perKata != NULL){
        alphabetOnlyCoy(perKata, kataAlphabetOnly);

        if(strlen(kataAlphabetOnly) > 0 && kataSudahDitemukan(&kata, kataAlphabetOnly) == 0){
            strcpy(kata.kata[kata.totalKata], kataAlphabetOnly);
            kata.totalKata++;
        }

        perKata = strtok(NULL, " \n");
    }
    fclose(fptr);

    FILE *out = fopen("kosa-kata.txt", "w");

    if (out == NULL) {
        printf("[!] Tidak dapat membuat file kosa-kata.txt\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < kata. totalKata; i++) {
        fprintf(out, "%s=\n", kata.kata[i]);
    }

    fclose(out);

    printf("[+] Berhasil! File kosa-kata.txt telah dibuat.\n");

    return EXIT_SUCCESS;
}