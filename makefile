# Name
PROG = oglBasics

# Compiler
CC = g++

# Compiler flags
CF = -c -Wall -pedantic -ansi

# Library flags
LF = -lgdi32 -lopengl32

# .o files
OBJ = main.o

# binding...
$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(OBJ) $(LF)
	rm $(OBJ)

# compiling...
%.o: src/%.cpp
	$(CC) $(CF) $<
