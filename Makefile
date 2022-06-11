CC = gcc
CPPFLAGS = -g -Wall -Werror -Wextra -Wno-unused-parameter -Wshadow -Wdouble-promotion -Wformat=2 -Wno-unused-variable -Wno-unused-result -fno-common -Wconversion  -Wno-missing-field-initializers -Werror=implicit-function-declaration -pedantic
OBJS = tests/test_list.c src/list.c
TARGET = ./a.out

.PHONY: compile run valgrind clean

default: run

compile : $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) -o $(TARGET)

run: compile
	$(TARGET)

valgrind: compile
	valgrind  --tool=memcheck -s --leak-check=full --show-leak-kinds=all ./example.o

clean:
	-rm -f *.o
	-rm -f $(TARGET)