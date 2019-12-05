CC=g++
CFLAGS=-I. -Wall
DEPS = cube.h
OBJ = cube.o driver.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

run:
	driver.exe
