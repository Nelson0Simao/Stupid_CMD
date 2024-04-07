#include "cmd_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

