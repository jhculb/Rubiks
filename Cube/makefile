CC=g++
CFLAGS=-I. -Wall
DEPS = cube.hpp IOfunctions.hpp
OBJ = cube.o driver.o IOfunctions.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

run:
	driver.exe
