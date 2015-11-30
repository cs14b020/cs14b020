all:finalprog

finalprog:BalancedCheck FindPosition

objects:cs14b020_p2.o cs14b020_p3.o stack.o

BalancedCheck:cs14b020_p2.o stack.o
	gcc stack.o cs14b020_p2.o -o BalancedCheck

cs14b020_p2.o: cs14b020_p2.c stack.h
	gcc -c cs14b020_p2.c

FindPosition:cs14b020_p3.o stack.o
	gcc stack.o cs14b020_p3.o -o FindPosition

cs14b020_p3.o: cs14b020_p3.c stack.h
	gcc -c cs14b020_p3.c

stack.o:stack.c stack.h
	gcc -c stack.c

clean:
	rm *o finalprog stack

tar:
	tar -cf ../cs14b020_lab5.tar.gz ../cs14b020_lab5
