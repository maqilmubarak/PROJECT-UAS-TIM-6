#include <stdio.h>
#include <string.h>
#include "utils.h"

void safe_gets(char *buf, size_t n) {
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