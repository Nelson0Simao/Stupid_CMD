#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

// função para criar o arquivo [hisotry de command]
void fn_show_history_command(){

}


void fn_create_file(){

}

void fn_exists_loop(){

}

void lb_clear_screen(){
    system("clear");
}

void fn_exec_file(char *argCommand){
    char *program = argCommand;
    if (strncmp(program, "./", 2) == 0) {
        char command[100];
        snprintf(command, sizeof(command), "chmod +x %s", program);
    }
}

void lb_dir(const char *diretorio){
    struct dirent *entry;
    DIR *dir = opendir(diretorio);

    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

char* lb_pwd(){
    char* buffer = NULL;
    size_t size = 0;

    if (getcwd(NULL, 0) == NULL) {
        perror("Erro ao obter o diretório atual");
        return NULL;
    }

    char* current_directory = getcwd(buffer, size);
    if (current_directory == NULL) {
        perror("Erro ao obter o diretório atual");
        return NULL;
    }

    return current_directory;
}


void fn_execute_command(const char *command){
    if (strcmp(command, "pwd") == 0){
        char *path = lb_pwd();
        printf("%s\n", path);
    }
    else if (strcmp(command, "ls") == 0){
        char *path = lb_pwd();
        lb_dir(path);
        free(path);
    }
    else if (strcmp(command, "cls") == 0){
        lb_clear_screen();
    }
    else{
        printf("MiniBash: %s: comando não encontrado\n", command);
    }
}
