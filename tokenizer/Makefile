all: test

CFLAGS = -g -O2

test: test.o mytoc.o
	cc -o test test.o mytoc.o
clean:
	rm -f  *.o test test.exe
