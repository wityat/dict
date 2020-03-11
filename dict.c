//
// Created by victor on 10.03.2020.
//
#include "value.h"
#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

Value val;

void add_memory(Dict dict){
    dict.size_max *= 2;
    dict.keys = realloc(&dict.keys, dict.size_max* sizeof(char**));
    dict.values = realloc(&dict.values, dict.size_max* sizeof(Value));
}

Value* get(Dict dict, const char* key){
    for(int i = 0;i < dict.size_now; i++){
        if (key == dict.keys[i])
            return &dict.values[i];
    }
    val.type = ERROR;
    return &val;
}

void put_into_size_now(Dict dict, char* key, Value value){
    dict.keys[dict.size_now] = key;
    dict.values[dict.size_now] = value;
}

void put(Dict dict, char* key, Value value){
    if (dict.size_now < dict.size_max) {
        Value* value_ = get(dict, key);
        if (value_->type == ERROR) {
            put_into_size_now(dict, key, value);
            dict.size_now++;}
        else{
            value_ = &value;
        }
    } else if (dict.size_now == dict.size_max){
        add_memory(dict);
        put_into_size_now(dict, key, value);
    } else{
        printf("ERROR!!!");
    }
}

void print_dict(Dict dict){
    for (int i = 0; i < dict.size_now; i++){
        switch (dict.values[i].type){
            case STRING:
                printf("%d. %s - %s", i, dict.keys[i], dict.values[i].string_value);
                break;
            case INT:
                printf("%d. %s - %d", i, dict.keys[i], dict.values[i].int_value);
                break;
            case FLOAT:
                printf("%d. %s - %f", i, dict.keys[i], dict.values[i].float_value);
                break;
            default:
                printf("ERROR!!!");
                break;
        }

    }
}

void pop(Dict dict, const char* key){
    for(int i = 0; i < dict.size_now; i++){
        if (dict.keys[i] == key) {
            dict.keys[i] = dict.keys[dict.size_now - 1];
            dict.values[i] = dict.values[dict.size_now - 1];
            dict.size_now --;
        }
    }
}
