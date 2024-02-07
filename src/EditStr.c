
#include "stdio.h"
#include "EditStr.h"

void str_copy(char* tostr,char* formstr){
    while(*formstr != '\0'){
        *tostr = *formstr;
        formstr++;
        tostr++;
    }
    while(*tostr != '\0'){
        *tostr = '\0';
        tostr++;
    }
    return;
}

int isEqual(char* str_0,char* str_1){
    while(*str_0 != '\0'){
        if(*str_0 != *str_1) return 0;
        str_0++;
        str_1++;
    }
    if(*str_1 != '\0')return 0;
    return 1;
}
