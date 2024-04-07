#include "cmd_commands.h"
#include <stdlib.h>

// Implementação da função para executar comandos externos
void execute_external_command(const char* command) {
    system(command);
}

