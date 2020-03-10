//
// Created by victor on 10.03.2020.
//

#ifndef DICT_DICT_H
#define DICT_DICT_H
#include "value.h"
typedef struct {
    char** keys;
    Value* values;
    int size_now;
    int size_max;
} Dict;
Value* get(Dict dict, const char* key);
void put(Dict dict, char* key, Value value);
void add_memory(Dict dict);
int pars_input_key(char* key, Value* value);
void print_dict(Dict dict);
#endif //DICT_DICT_H
