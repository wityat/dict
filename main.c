#include <stdio.h>
#include "stdlib.h"
#include "dict.h"
#include "string.h"

int main() {

    Dict dict;
    setup(&dict);

    printf("You are WELCOME into NEW AWESOME PROGRAM, which simulate dictionary!\n "
           "Please, enter 'help', if you don't know how to use this.\n\n");

    for (char *c = (char*) calloc(100, sizeof(char)); strcmp("quit", c) != 0; scanf("%s", c)) {
        if (strcmp("help", c) == 0) {
            printf("THIS IS HELP!\n\n"
                   "get - to go into 'get value from key' mode\n"
                   "put - to go into 'insert a value by key' mode\n"
                   "pop - to go into 'delete a value by key' mode\n"
                   "show_dict - to show all dict\n\n");

        }else if(strcmp("get", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in GET MODE\n"
                   "Enter a KEY for get a value!\n\n");
            scanf("%s", c);
            Value* value = get(&dict, c);
            if (value->type != ERROR){
                printf("Your VALUE from this key is:\n");
                print_value(value);}
            else
                printf("There is NO value with current key!\n");

        }else if(strcmp("put", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in PUT MODE\n"
                   "Enter a KEY, when you wanna insert value!\n\n");
            char *key = (char*) calloc(100, sizeof(char));
            scanf("%s", key);
            printf("Enter a VALUE, for current key!\n\n");
            char *val_ = (char*) calloc(100, sizeof(char));
            scanf("%s", val_);
            Value* value = pars_input_value(val_);
            put(&dict, key, *value);
            free(key);
            free(val_);
            print_dict(&dict);
        }else if(strcmp("pop", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in POP MODE\n"
                   "Enter a KEY, when you wanna delete value!\n\n");
            scanf("%s", c);
            pop(&dict, c);
            print_dict(&dict);
        }else if(strcmp("show_dict", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in SHOW DICT MODE\n\n");
            print_dict(&dict);
        }else{
            printf("Please, if you don't know how to use this, enter 'help'!\n\n");
        }

    }
    free(dict.values);
    free(dict.keys);
    free(&dict.size_max);
    free(&dict.iterator);
    free(&dict);


    return 0;
}
