
#include "stdio.h"
#include "option.h"

void op_tag(Command_* commands,char* tag[]){
    if(*tag == "-t"){
        tag++;
        int i = 0;
        while(*(*tag) != '\0'){
            *commands->text_path = *(*tag);
            *tag++;
            i++;
        }
    }
    else if(*tag == "-n"){
        tag++;
        int i = 0;
        while(*(*tag) != '\0'){
            *commands->text_path = *(*tag);
            *tag++;
            i++;
        }
    }else{
        printf("Can't no expect option");
        //exit(1);
    }
};

void option(Command_* commands,char* argv[]){
    argv++;
    int i = 0;
    while(*(*argv) != '\0'){
        (*commands->text_path) = *(*argv);
        *argv++;
        i++;
    }
    argv++;
    while(*argv != NULL){
        op_tag(commands,argv);
        argv++;
    }
}
