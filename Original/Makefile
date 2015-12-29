# PROJECT EULER SOLUTIONS
#
CC 		= g++
CFLAGS 	= -c -Wall
LDFLAGS	= 
SRC		= main.cpp Solution.cpp helperFunctions.cpp
OBJ		= $(SRC:.cpp=.o)
EXE		= PE

all: $(SRC) $(EXE)

$(EXE):	$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONEY: clean
clean:	
	del *.o $(EXE).exe
