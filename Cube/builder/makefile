<<<<<<< HEAD:Cube/builder/makefile
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
=======
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
>>>>>>> cd47b5bc8e21feeaf3bf86aba628e7ec872a554b:Cube/makefile
