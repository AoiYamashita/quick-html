#include "stdio.h"

int main(int argc, char* argv[]){
    //No input
    if (argv[1] == NULL){
        printf("No text file path\n");
        return 1;
    }
    //inisial file name is index.html
    char file_name[] = "index.html";
    char title[] = "Document";
    
    //command
    int path_ = 1;
    if(argv[1][0] == '-'){
        path_++;
    }

    //read text file
    FILE *read_file;
    read_file = fopen(argv[path_], "r");
    if(read_file == NULL){
        printf("Can't search text file\n");
        return 1;
    }

    //is html file exsited ?
    FILE *_file;
    _file = fopen(file_name, "r");
    if(_file != NULL){
        printf("existed html file\n");
        return 1;
    }

    //make html file and insiarize
    FILE *make_file;
    make_file = fopen(file_name, "w");
    if(make_file == NULL){
        printf("Can't ceate html file\n");
        return 1;
    }
    fclose(make_file);

    //write html file
    FILE *html_file;
    html_file = fopen(file_name, "a");
    if(html_file == NULL){
        printf("Can't write html file\n");
        return 1;
    }

    char innerHtml[] = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>%s</title>\n</head>\n<body>\n";

    fprintf(html_file,innerHtml,title);

    while(fscanf(read_file, "%s", ) > 0){

    }
    fprintf(html_file,"</body>\n</html>\n");
    fclose(html_file);
    fclose(read_file);
    return 0;
}