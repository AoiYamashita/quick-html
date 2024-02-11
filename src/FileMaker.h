#ifndef FMAKER_H
#define FMAKER_H

#include "stdio.h"
#include "EditStr.h"

void initFile(char* file);

char* MakeFrase(char* txt_data);

void MakeFile(FILE *read_file,FILE *html_file);

#endif