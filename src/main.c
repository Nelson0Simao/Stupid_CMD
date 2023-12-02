#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bash.h>

typedef struct Node{
    char text[100];
    struct Node* prox;
  } Node;

  Node* add_hist(Node* list, const char* text){
    Node* No = (Node*) malloc(sizeof(Node));
    if (!No) {
      printf("Err aloc memory\n");
      exit(EXIT_FAILURE);
    }

    strncpy(No->text, text, sizeof(No->text));
    No->text[sizeof(No->text) - 1 ] = '\0';

    No->prox = list;
    return No;
  }

  void show_hist(Node* list){
    while (list != NULL) {
      printf("%s\n", list->text);
      list = list->prox;
    }
  }

  void free_hist(Node* list){
    while(list != NULL){
      Node* tmp = list;
      list = list->prox;
      free(tmp);
    }
  }

// autocomplete
void fn_find_matches(Node* list, const char* prefix) {
  // printf("show word %s\n", prefix);
  int i = 0;
  while (list != NULL) {

    if (strncmp(list->text, prefix, strlen(prefix)) == 0){
       printf("%i- %s\n",i++, list->text);
    }
    list = list->prox;
  }
}

int main(void){
    char *command = NULL;
    Node* list = NULL;

    command = (char *)malloc(100 * sizeof(char));

    lb_clear_screen();

    while( EOF != '\n'){
        printf("MiniBash:>");
    // scanf("%99s", command);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';  
        list = add_hist(list, command);

        fflush(stdin);

        fn_exec_file(command);

        if (strcmp(command, "exit")== 0){
            break;
        }
        if (strcmp(command, "history")== 0){
            show_hist(list);
            continue;
        }
        if (strncmp(command, "cd ", 3) == 0) {
          char *path = command + 3;
          if (chdir(path) == 0){
            continue;
          }else{
            perror("cd");
          }
        }
        fn_find_matches(list, command);
        fn_execute_command(command);
    }
    free_hist(list);
    free(command);
    return 0;
}


