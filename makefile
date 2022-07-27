CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = hw15.o
FILES = hw15.cpp

all: hw15

hw15: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o hw15

hw15.o: hw15.cpp
	$(CC) $(FLAGS) -c hw15.cpp

tar:
	tar -cf hw15.tar hw15.scr Makefile $(FILES)

clean:
	rm *.o *.tar *.scr hw15

sudoClean:
	rm *.o *.scr hw15