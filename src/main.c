#include <stdio.h>
#include "EditStr.h"
#include "option.h"
#include "FileMaker.h"

Command_ file_data = {".text","index.html","Document"};

char *code[] = {"p","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","h","0","0","a src","0","0","0","ul","ol","0","0","0","0","0","0","0","0","0","0","0","0","0","0","input","0","0","0","0","canvas","img","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","br","0","0","botton","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","table","0","0","0","0"};

int main(int argc, char* argv[]){
    //No input
    if (argv[1] == NULL){
        printf("No text file path\n");
        return 1;
    }

    option(&file_data,argc,argv);

    //read text file
    FILE *read_file;
    read_file = fopen(file_data.text_path, "r");
    if(read_file == NULL){
        printf("Can't search text file\n");
        return 1;
    }

    //is html file exsited ?
    FILE *_file;
    _file = fopen(file_data.file_name, "r");
    if(_file != NULL){
        printf("existed html file\n");
        return 1;
    }

    //make html file and insiarize
    FILE *make_file;
    make_file = fopen(file_data.file_name, "w");
    if(make_file == NULL){
        printf("Can't ceate html file\n");
        return 1;
    }
    fclose(make_file);

    //write html file
    FILE *html_file;
    html_file = fopen(file_data.file_name, "a");
    if(html_file == NULL){
        printf("Can't write html file\n");
        return 1;
    }

    char innerHtml[256];

    initFile(innerHtml);

    fprintf(html_file,innerHtml,file_data.title);

    char text_data[] = "";

    while(fscanf(read_file, "%s", text_data) > 0){
        char *text_p = &text_data[0];
        char tag_[100] = "";
        int tag_flag = 0;
        //search tag
        while(code[(int)(*text_p)] != "0"){
            if(tag_flag == 0){
                char *code_ = code[(int)(*text_p)];
                while(*code_ != '\0'){
                    tag_[tag_flag] = *code_;
                    tag_flag++;
                    code_++;
                }
                tag_flag = 0;
            }
            tag_flag++;
            text_p++;
        }
        if(tag_[0] == 'h'){
            tag_[1] = tag_flag+'0';
        }
        fprintf(html_file,"<%s>",tag_);
        //write text
        while(*text_p != '\0'){
            fprintf(html_file,"%c",*text_p);
            text_p++;
        }
        //end tag
        fprintf(html_file,"</%s>\n",tag_);
    }
    fprintf(html_file,"\n</body>\n</html>\n");
    fclose(html_file);
    fclose(read_file);
    return 0;
}