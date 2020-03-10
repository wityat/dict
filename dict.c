//
// Created by victor on 10.03.2020.
//
#include "value.h"
#include "dict.h"


Value get(Dict dict, char key){
    for(int i = 0;i < dict.size_now; i++){
        if (key == dict.keys[i])
            return dict.values[i];
    }
    Value val;
    val.type = ERROR;
    return val;
}

void put(Dict dict, char* key, Value value){

}
