# Makefile tutorial courtesy: 
# 	http://mrbook.org/blog/tutorials/make/
#

# Version 1.2: slightly more complex
# CC = g++
# CFLAGS = -c -Wall
# 
# all: hello
# 
# hello: main.o factorial.o hello.o
# 	$(CC) main.o hello.o factorial.o -o hello
# 
# main.o : main.cpp
# 	$(CC) $(CFLAGS) main.cpp
# 
# factorial.o: factorial.cpp
# 	$(CC) $(CFLAGS) factorial.cpp
# 
# hello.o: hello.cpp
# 	$(CC) $(CFLAGS) hello.cpp
# 
# clean:
# 	del *.o hello
#

# Version 2.0: full Makefile
CC 		= g++
CFLAGS 	= -c -Wall
LDFLAGS = 
SRC 	= main.cpp hello.cpp factorial.cpp
OBJ 	= $(SRC:.cpp=.o)
EXE 	= hello

all: $(SRC) $(EXE)
	nmake clean

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.cpp.o: 
	$(CC) $(CFLAGS) $< -o $@

.PHONEY: clean
clean: 
	del *.o
