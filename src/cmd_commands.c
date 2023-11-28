#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "cmd_utils.h"

void custom_ls() {
    DIR* dir = opendir(".");

    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
  }

void custom_cd(const char* path) {
    if (chdir(path) == 0) {
        // Sucesso
    } else {
        perror("Erro ao mudar de diretório");
    }
}



