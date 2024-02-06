#ifndef OPTION_H
#define OPTION_H

typedef struct{
    char text_path[128];
    char file_name[128];
    char title[128];
} Command_;

void option(Command_* commands,char* argv[]);

void op_tag(Command_* commands,char* tag[]);

#endif