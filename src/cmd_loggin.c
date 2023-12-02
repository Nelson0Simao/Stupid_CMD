#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "cmd_utils.h"

bool is_validLogin(const struct t_input_data *input, const struct t_user *user){
    //printf("\n [DEBUGGER]# username: %s password: %s\n", input->user_name, input->passwd);
    if( input == NULL || user == NULL ){

        return false;
    }
    if (strcmp(input->user_name, user->user_name) == 0 && strcmp(input->passwd, user->passwd) == 0) {

        return true;
    }else{

        return false;
    }
    return false;
}

