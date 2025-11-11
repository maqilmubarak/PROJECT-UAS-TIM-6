#ifndef LOGIN_H
#define LOGIN_H
#include "fileio.h"

Account* find_account(const char* username);

int authenticate_cli(const char* username);
int add_account(const char* user, const char* pass);

#endif