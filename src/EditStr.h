#ifndef ESTR_H
#define ESTR_H

typedef struct{
    char text_path[128];
    char file_name[128];
    char title[128];
} Command_;

void str_copy(char* tostr,char* formstr);

int isEqual(char* str_0,char* str_1);

#endif