
#include "FileMaker.h"

char *code[] = {"p","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","h1","0","0","a src","0","0","0","ul","ol","0","0","0","0","0","0","0","0","0","0","0","0","0","0","input","0","0","0","0","canvas","img","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","br","0","0","botton","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","table","0","0","0","0"};

void initFile(char* file){
    str_copy(file,"<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>%s</title>\n</head>\n<body>\n");
    return;
}

char* tag_base[] = {"<",">","</"};

char* MakeFrase(char* txt_data){
    char html_data[100000] = "";
    char tag[100] = "";
    while(*txt_data != '\0'){
        if(*txt_data == '\n'){
            txt_data++;
            continue;
        }
        if((int)*txt_data > 0 && code[(int)*txt_data] != "0"){
            if(code[(int)*txt_data] == tag || (tag[0] == code[(int)*txt_data][0] && code[(int)*txt_data][0] == 'h')){
                char tag_frase[] = "</";
                str_cat(tag_frase,tag);
                str_cat(tag_frase,tag_base[1]);
                str_cat(html_data,tag_frase);

                str_copy(txt_data,html_data);
                return txt_data;
            }
            else if(!isEqual(tag,""))str_cat(html_data,MakeFrase(txt_data));

            str_copy(tag,code[(int)*txt_data]);
            int i = 2;
            while(code[(int)*(txt_data+1)] == "h1"){
                str_copy(tag,code[(int)*txt_data]);
                tag[1] = i+'0';
                txt_data++;
                i++;
            }
            char tag_frase[10000] = "<";
            str_cat(tag_frase,tag);
            str_cat(tag_frase,tag_base[1]);
            str_cat(html_data,tag_frase);
        }else{
            add_char(html_data,*txt_data);
        }
        txt_data++;
    }
    
    if(isEqual(tag,"")){
        char html[1000] = "<p>";
        str_cat(html,html_data);
        str_copy(html_data,html);
        str_copy(tag,code[0]);
    }
    //printf("%d %d %d %d %d %d %d %d %d %d\n",tag[0],tag[1],tag[2],tag[3],tag[4],tag[5],tag[6],tag[7],tag[8],tag[9]);
    char tag_frase[] = "</";
    str_cat(tag_frase,tag);
    //printf("%s %s\n",tag,tag_frase);
    str_cat(tag_frase,tag_base[1]);
    str_cat(html_data,tag_frase);
    str_copy(txt_data,html_data);
    return txt_data;
}

void MakeFile(FILE *read_file,FILE *html_file){
    char text_data[100000];
    while(fgets(text_data, 100000, read_file) > 0){//fscanf(read_file, "%s\n", text_data) > 0){
        fprintf(html_file, "%s\n",MakeFrase(text_data));
    }
    return;
}