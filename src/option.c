#include "option.h"

int op_tag(Command_* commands,char* tag[]){
    int i = 0;
    if(isEqual(*tag,"-t")){
        tag++;
        i++;
        str_copy(&(*commands->title),*tag);
    }
    else if(isEqual(*tag,"-n")){
        tag++;
        i++;
        str_copy(&(*commands->file_name),*tag);
    }else{
        printf("Can't no expect option\n");
        //exit(1);
    }
    return i;
};

void option(Command_* commands,int argc,char* argv[]){
    int i = 0;
    argv++;
    i+=2;
    str_copy(&(*commands->text_path),*argv);
    argv++;
    while(i < argc){
        int t = op_tag(commands,argv);
        i += t+1;
        argv += t+1;
    }
}
