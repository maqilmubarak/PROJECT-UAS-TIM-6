#ifndef LOGIN_H
#define LOGIN_H
#include "../fileio/fileio.h"

Account* findAccount(const char* username);
Account* authenticateCli(int argc, char *argv[]);


#endif