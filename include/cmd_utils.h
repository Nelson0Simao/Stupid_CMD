#include <stdbool.h>

#define MAX_PASSWD 20
#define MAX_USERNAME 20

#ifndef SHELL_UTILS_H
#define SHELL_UTILS_H

struct t_user {
    char user_name[MAX_USERNAME];
    char passwd[MAX_PASSWD];
};

struct t_input_data {
    char user_name[MAX_PASSWD];
    char passwd[MAX_PASSWD];
};

void custom_ls();
void custom_cd(const char* path);

#endif

