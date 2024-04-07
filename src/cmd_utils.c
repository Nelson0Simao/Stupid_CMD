#include "cmd_utils.h"

// Implementação da função custom_ls
void custom_ls() {
    // Abre o diretório atual
    DIR* dir = opendir(".");

    // Verifica se houve erro na abertura do diretório
    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        return;
    }

    // Lê e imprime os nomes dos arquivos e diretórios no diretório atual
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Fecha o diretório
    closedir(dir);
}

// Implementação da função custom_cd
void custom_cd(const char* path) {
    // Tenta mudar para o diretório especificado
    if (chdir(path) == 0) {
        // Sucesso
    } else {
        // Se houver erro, exibe uma mensagem de erro
        perror("Erro ao mudar de diretório");
    }
}

// Implementação da função custom_pwd
void custom_pwd() {
    char* current_directory = getcwd(NULL, 0);
    if (current_directory == NULL) {
        perror("Erro ao obter o diretório atual");
    } else {
        printf("C:%s>", current_directory);
        free(current_directory);
    }
}

// Implementação da função custom_clear
void custom_clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Implementação da função custom_mkdir
void custom_mkdir(const char* dirname) {
    if (mkdir(dirname, 0777) == 0) {
        // Sucesso
    } else {
        perror("Erro ao criar diretório");
    }
}

// Implementação da função custom_touch
void custom_touch(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
    } else {
        perror("Erro ao criar arquivo");
    }
}

