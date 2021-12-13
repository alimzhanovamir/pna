all: exe lib

exe: main.c hello.h lib

	gcc main.c -L. -lHello -o hello

lib: hello.c hello.h
	gcc -shared hello.c -o libHello.so

clean:
	-rm hello libHello.so 2>/dev/null
