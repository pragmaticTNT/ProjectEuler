# PROJECT EULER SOLUTION BATCH 1
#
CC 		= g++
CFLAGS 	= -c -Wall
LDFLAGS	= 
SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)
EXE		= Batch1

all: $(SRC) $(EXE)

$(EXE):	$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONEY: clean
clean:	
	del *.o $(EXE).exe
