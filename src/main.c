#include "cmd_commands.h"
#include "cmd_utils.h"

#define MAX_COMMAND_SIZE 100
#define MAX_ARGS 64

typedef struct Node {
    char text[MAX_COMMAND_SIZE];
    struct Node* next;
} Node;

Node* add_history(Node* history, const char* command) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    strncpy(new_node->text, command, sizeof(new_node->text) - 1);
    new_node->text[sizeof(new_node->text) - 1] = '\0';

    new_node->next = history;
    return new_node;
}

void show_history(const Node* history) {
    int count = 1;
    while (history != NULL) {
        printf("%d. %s\n", count++, history->text);
        history = history->next;
    }
}

void free_history(Node* history) {
    while (history != NULL) {
        Node* tmp = history;
        history = history->next;
        free(tmp);
    }
}

void custom_pwd() {
    char* current_directory = getcwd(NULL, 0);
    if (current_directory == NULL) {
        perror("Erro ao obter o diretório atual");
    } else {
        printf("C:%s>", current_directory);
        free(current_directory);
    }
}

void custom_clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void custom_mkdir(const char* dirname) {
    if (mkdir(dirname, 0777) == 0) {
        // Sucesso
    } else {
        perror("Erro ao criar diretório");
    }
}

void custom_touch(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
    } else {
        perror("Erro ao criar arquivo");
    }
}

void execute_external_command(const char* command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Erro ao criar processo");
    } else if (pid == 0) {
        // Processo filho
        execlp(command, command, (char*)NULL);
        // Se execvp retornar, houve um erro
        perror("Erro ao executar comando externo");
        exit(EXIT_FAILURE);
    } else {
        // Processo pai
        int status;
        waitpid(pid, &status, 0);

        if (!WIFEXITED(status)) {
            // O processo filho não terminou normalmente
            perror("Erro ao aguardar o término do processo filho");
        }
    }
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
        } else if (strcmp(command, "ls") == 0) {
            custom_ls();
        } else if (strncmp(command, "cd ", 3) == 0) {
            char* path = command + 3;
            custom_cd(path);
        } else if (strcmp(command, "pwd") == 0) {
            custom_pwd();
            printf("\n");  // Adiciona uma nova linha
        } else if (strcmp(command, "clear") == 0) {
            custom_clear();
        } else if (strncmp(command, "mkdir ", 6) == 0) {
            char* dirname = command + 6;
            custom_mkdir(dirname);
        } else if (strncmp(command, "touch ", 6) == 0) {
            char* filename = command + 6;
            custom_touch(filename);
        } else {
            execute_external_command(command);
        }
    }

    free_history(history);

    return 0;
}

