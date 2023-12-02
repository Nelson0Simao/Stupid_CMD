#ifndef SHELL_UTILS_H
#define SHELL_UTILS_H

struct t_user {
    char user_name[20];
    char passwd[20];
};

void custom_ls();
void custom_cd(const char* path);
bool custom_login(const struct t_user);
// Adicione protótipos para outras funções de utilidade

#endif

