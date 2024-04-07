#include "cmd_commands.h"
#include "cmd_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_SIZE 100

// Definição da estrutura Command
typedef struct {
    char name[20]; // Nome do comando
    void (*execute)(const char*);
} Command;

void execute_internal_command(const char* command) {
    static Command internal_commands[] = {
        {"ls", custom_ls},
        {"cd", custom_cd},
        {"pwd", custom_pwd},
        {"clear", custom_clear},
        {"mkdir", custom_mkdir},
        {"touch", custom_touch}
    };
    int num_internal_commands = sizeof(internal_commands) / sizeof(internal_commands[0]);

    for (int i = 0; i < num_internal_commands; ++i) {
        if (strncmp(command, internal_commands[i].name, strlen(internal_commands[i].name)) == 0) {
            internal_commands[i].execute(command + strlen(internal_commands[i].name) + 1);
            return;
        }
    }

    printf("Comando interno não reconhecido.\n");
}

int main(void) {
    char command[MAX_COMMAND_SIZE];
    Node* history = NULL;

    custom_clear();
    while (1) {
        custom_pwd();  // Mostra o diretório atual

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        // Adiciona ao histórico
        history = add_history(history, command);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "history") == 0) {
            show_history(history);
        } else {
            execute_internal_command(command);
        }
    }

    free_history(history);

    return 0;
}

