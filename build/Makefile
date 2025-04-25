CC = gcc
CFLAGS = -fpic -c

SRC = ../src
TESTS = ../tests
TARGET = sl/libsl.so

all: clear $(TARGET)
	rm -rf *.o

$(TARGET):
	mkdir -p sl
	$(CC) $(CFLAGS) $(SRC)/sl.c
	$(CC) -shared -o $(TARGET) sl.o
	cp $(SRC)/sl.h sl


test: $(TARGET)
	mkdir -p tests
	$(CC) -Isl -Lsl/ -lsl -Wl,-rpath=sl $(TESTS)/simple_test.c -o tests/t_s
	$(CC) -Isl -Lsl/ -lsl -Wl,-rpath=sl $(TESTS)/long_string_test.c -o tests/t_ls

	tests/t_s
	tests/t_ls

clear:
	rm -rf *.o
	rm -rf sl
	rm -rf tests