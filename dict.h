//
// Created by victor on 10.03.2020.
//

#ifndef DICT_DICT_H
#define DICT_DICT_H
#include "value.h"
typedef struct {
    char* keys;
    Value* values;
    int size_now;
    int size_max;
} Dict;
Value get(Dict dict, char key);
void put(Dict dict, char* key, Value value);
#endif //DICT_DICT_H
