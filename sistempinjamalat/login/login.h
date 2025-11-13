#ifndef LOGIN_H
#define LOGIN_H
#include "fileio.h"

Account* findAccount(const char* username);
Account* authenticateCli();

int addAccount(const char* user, const char* pass, const char* role);

#endif