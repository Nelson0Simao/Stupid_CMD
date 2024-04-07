#ifndef CMD_UTILS_H
#define CMD_UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_COMMAND_SIZE 100

// Definição do tipo Node
typedef struct Node {
    char text[MAX_COMMAND_SIZE];
    struct Node* next;
} Node;

// Protótipos das funções relacionadas a comandos utilitários
void custom_ls();
void custom_cd(const char* path);
void custom_pwd();
void custom_clear();
void custom_mkdir(const char* dirname);
void custom_touch(const char* filename);

// Protótipos das funções relacionadas ao histórico
Node* add_history(Node* history, const char* command);
void show_history(const Node* history);
void free_history(Node* history);

#endif /* CMD_UTILS_H */

