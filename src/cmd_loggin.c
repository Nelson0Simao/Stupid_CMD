#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWD 20
#define MAX_USERNAME 20

struct t_user {
    char user_name[MAX_USERNAME];
    char passwd[MAX_PASSWD];
};

struct t_input_data {
    char user_name[20];
    char passwd[20];
};

bool is_validLogin(const struct t_input_data *input, const struct t_user *user){
//    printf("\n [DEBUGGER]# username: %s password: %s\n", input->user_name, user->passwd);
    if( input == NULL || user == NULL ){

        return false;
    }
    if (strcmp(input->user_name, user->passwd) == 0 && strcmp(input->user_name, user->passwd) == 0) {

        return true;
    }else{

        return false;
    }
    return false;
}
//int custom_login(){

