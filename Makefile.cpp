pokdeng: pokdeng.c pokdenglib.o pokdeng.h
	gcc -o pokdeng pokdeng.c pokdenglib.o
pokdenglib.o: pokdeng.c pokdeng.h
	gcc -c pokdenglib.c
clean:
	rm -rf *.o pokdeng
