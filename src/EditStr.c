
#include "stdio.h"
#include "EditStr.h"

void str_cat(char* basestr,char* addstr){
    while(*basestr != '\0')basestr++;
    while(*addstr != '\0'){
        *basestr = *addstr;
        addstr++;
        basestr++;
    }
    return;
}

void str_copy(char* tostr,char* fromstr){
    while(*fromstr != '\0'){
        *tostr = *fromstr;
        fromstr++;
        tostr++;
    }
    while(*tostr != '\0'){
        *tostr = '\0';
        tostr++;
    }
    return;
}

void add_char(char* base,char add){
    while(*base != '\0')base++;
    *base = add;
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
