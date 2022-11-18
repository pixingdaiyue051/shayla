CFLAGS=-Wall -g

cleanext:
        rm -f ext
cleanextout:
        rm -f ext.out mystr.o
ext.out:ext.c mystr.o
        gcc ext.c mystr.o -o ext.out
mystr.o:mystr.c
        gcc -c mystr.c -o mystr.o