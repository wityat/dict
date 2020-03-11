#include <stdio.h>
#include "stdlib.h"
#include "dict.h"
#include "string.h"

int main() {

    Dict dict;
    setup(&dict);

    printf("You are WELCOME into NEW AWESOME PROGRAM, which simulate dictionary!\n "
           "Please, enter 'help', if you don't know how to use this.\n\n");

    for (char *c = calloc(sizeof(char*), 100); strcmp("quit", c) != 0; scanf("%s", c)) {
        if (strcmp("help", c) == 0) {
            printf("THIS IS HELP!\n\n"
                   "get - to go into 'get value from key' mode\n"
                   "put - to go into 'insert a value by key' mode\n"
                   "pop - to go into 'delete a value by key' mode\n"
                   "show_dict - to show all dict\n\n");

        }else if(strcmp("get", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in GET MODE\n"
                   "Enter a key for get a value!");
            scanf("%s", c);
            Value* value = get(&dict, c);
            if (value->type != ERROR){
                printf("Your value from this key is:\n");
                print_value(value);}
            else
                printf("There is NO value with current key!");

        }else if(strcmp("put", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in PUT MODE\n"
                   "Enter a KEY, when you wanna insert value!");
            char *key = calloc(sizeof(char*), 100);
            scanf("%s", key);
            printf("Enter a VALUE, for current key!");
            scanf("%s", c);
            Value* value = pars_input_value(c);
            put(&dict, key, *value);
            free(key);
        }else if(strcmp("pop", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in POP MODE\n"
                   "Enter a KEY, when you wanna delete value!");
            scanf("%s", c);
            pop(&dict, c);
        }else if(strcmp("show_dict", c) == 0){
            printf("Uhhu!\n"
                   "Now you are in SHOW DICT MODE\n\n");
            print_dict(&dict);
        }else{
            printf("Please, if you don't know how to use this, enter 'help'!\n\n");
        }
    }
    free(&dict);

    return 0;
}
