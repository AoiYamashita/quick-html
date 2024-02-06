#/usr/bin/bash

gcc src/main.c src/option.c -o test
rm index.html 
./test test.txt
code index.html 