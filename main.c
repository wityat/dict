#include <stdio.h>
#include "dict.h"
#include "string.h"

int main() {

    Dict dict;
    setup(&dict);

    printf("You are WELCOME into NEW AWESOME PROGRAM, which simulate dictionary!\n "
           "Please, enter 'h', if you don't know how to use this.");

    for(char* c = 0; strcmp("quit", c) != 0; scanf("%s", c)){

        if (strcmp("help", c) != 0) {
            printf("THIS IS HELP!\n\n"
                   "get - to go into 'get value from key' mode\n"
                   "put - to go into 'insert a value by key' mode\n"
                   "pop - to go into 'delete a value by key' mode\n\n");

        }else if(strcmp("get", c) != 0){
            printf("Uhhu!\n"
                   "Now you are in GET MODE\n"
                   "Enter a key for get a value!");
            scanf("%s", c);
            Value* value = get(&dict, c);
            if (value->type != ERROR){
                printf("Your value form this key is:\n");
                print_value(value);}
            else
                printf("There is NO value with current key!")

        }else if(strcmp("put", c) != 0){


        }else if(strcmp("pop", c) != 0){


        }else{

        }
    }
    return 0;
}
