//
// Created by victor on 10.03.2020.
//
#include "value.h"
#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

Value val;

Dict setup(Dict* dict){
    dict->size_max = BEGIN_SIZE;
    dict->iterator = 0;
    dict->keys = calloc(sizeof(char**), BEGIN_SIZE);
    dict->values = calloc(sizeof(Value), BEGIN_SIZE);
}

void add_memory(Dict* dict){
    dict->size_max *= 2;
    dict->keys = realloc(&dict->keys, dict->size_max* sizeof(char**));
    dict->values = realloc(&dict->values, dict->size_max* sizeof(Value));
}

Value* get(Dict* dict, const char* key){
    for(int i = 0;i < dict->iterator; i++){
        if (key == dict->keys[i])
            return &dict->values[i];
    }
    val.type = ERROR;
    return &val;
}

void put_into_size_now(Dict* dict, char* key, Value value){
    dict->keys[dict->iterator] = key;
    dict->values[dict->iterator] = value;
}

void put(Dict* dict, char* key, Value value){
    if (dict->iterator < dict->size_max) {
        Value* value_ = get(dict, key);
        if (value_->type == ERROR) {
            put_into_size_now(dict, key, value);
            dict->iterator += 1;}
        else{
            *value_ = value;
        }
    } else if (dict->iterator == dict->size_max){
        add_memory(dict);
        put_into_size_now(dict, key, value);
    } else{
        printf("ERROR!!!");
    }
}

void print_dict(Dict* dict){
    for (int i = 0; i < dict->iterator; i++){
        switch (dict->values[i].type){
            case STRING:
                printf("%d. %s - %s\n", i, dict->keys[i], dict->values[i].string_value);
                break;
            case INT:
                printf("%d. %s - %d\n", i, dict->keys[i], dict->values[i].int_value);
                break;
            case FLOAT:
                printf("%d. %s - %f\n", i, dict->keys[i], dict->values[i].float_value);
                break;
            default:
                printf("ERROR!!!\n");
                break;
        }

    }
}

void print_value(Value* value){
    switch (value->type){
        case STRING:
            printf("%s\n", value->string_value);
            break;
        case INT:
            printf("%d\n", value->int_value);
            break;
        case FLOAT:
            printf("%f\n", value->float_value);
            break;
        default:
            printf("ERROR!!!\n");
            break;
    }
}

Value* pars_input_value(char* value) {
    char *p = NULL;
    int int_value = (int) strtol(value, &p, 10);
    if (!*p) {
        val.type = INT;
        val.int_value = int_value;
    } else {
        float float_value = strtof(value, &p);
        if (!*p) {
            val.type = FLOAT;
            val.float_value = float_value;
        } else {
            val.type = STRING;
            val.string_value = value;
        }
    }
    return &val;
}

void pop(Dict* dict, const char* key){
    for(int i = 0; i < dict->iterator; i++){
        if (dict->keys[i] == key) {
            dict->keys[i] = dict->keys[dict->iterator - 1];
            dict->values[i] = dict->values[dict->iterator - 1];
            dict->iterator --;
        }
    }
}
