//
// Created by victor on 10.03.2020.
//

#ifndef DICT_DICT_H
#define DICT_DICT_H
#include "value.h"
#define BEGIN_SIZE 4
typedef struct {
    char** keys;
    Value* values;
    int iterator;
    int size_max;
} Dict;
Dict setup(Dict* dict);
Value* get(Dict* dict, const char* key);
void put(Dict* dict, char* key, Value value);
void pop(Dict* dict, const char* key);
void add_memory(Dict* dict);
Value* pars_input_value(char* value);
void print_value(Value* value);
void print_dict(Dict* dict);
#endif //DICT_DICT_H
