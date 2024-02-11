#ifndef ESTR_H
#define ESTR_H

typedef struct{
    char text_path[128];
    char file_name[128];
    char title[128];
} Command_;

void str_copy(char* tostr,char* fromstr);

void str_cat(char* basestr,char* addstr);

void add_char(char* base,char add);

int isEqual(char* str_0,char* str_1);

#endif