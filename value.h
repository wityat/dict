//
// Created by victor on 10.03.2020.
//

#ifndef DICT_VALUE_H
#define DICT_VALUE_H
enum Type {INT, FLOAT, STRING, ERROR};
typedef struct{
    enum Type type;
    union {
        int int_value;
        float float_value;
        char* string_value;
    };
} Value;
#endif //DICT_VALUE_H
