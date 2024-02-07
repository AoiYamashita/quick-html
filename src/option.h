#ifndef OPTION_H
#define OPTION_H

#include "stdio.h"
#include "EditStr.h"

void option(Command_* commands,int argc,char* argv[]);

int op_tag(Command_* commands,char* tag[]);

#endif