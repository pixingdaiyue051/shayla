#编译 linkedlist
main.out:caculator.o stack_data.o stack_ope.o caculator_main.c
	gcc caculator.o stack_data.o stack_ope.o caculator_main.c -o main.out
caculator.o:caculator.c
	gcc -c caculator.c -o caculator.o
stack_data.o:stack_data.c
	gcc -c stack_data.c -o stack_data.o
stack_ope.o:stack_ope.c
	gcc -c stack_ope.c -o stack_ope.o