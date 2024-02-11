#/usr/bin/bash -ex

gcc src/EditStr.c src/main.c src/option.c src/FileMaker.c -o test
rm index.html
sleep 1
./test ./test.txt
# -t sample -n hhh.html
code index.html 