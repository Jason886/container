#! /bin/bash

if [[ $1 == 'clean' ]] 
then
echo "rm -rf *.o test"
rm -rf *.o test
exit
fi

CFLAGS=-I./src -I./test

gcc -pedantic -std=c89 ${CFALGS} -c ./src/vec.c -o vec.o
gcc -pedantic -std=c89 ${CFLAGS} -c ./src/list.c -o list.o
gcc -pedantic -std=c89 ${CFLAGS} -c ./src/map.c -o map.o
gcc -pedantic -std=c89 ${CFLAGS} -c ./src/test.c -o test.o
gcc -pedantic -std=c89 ${CFLAGS} *.o -o test
rm -rf *.o
