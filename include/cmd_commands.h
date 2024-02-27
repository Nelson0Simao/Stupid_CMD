#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#ifndef SHELL_COMMANDS_H
#define SHELL_COMMANDS_H

void execute_external_command(const char* command);

#endif

