CC = g++
CFLAGS = -Wall -Wextra -pedantic -Wconversion
PROG = program
SRC = main.cpp member.cpp
HDR = member.h
OBJ = $(SRC:.cpp=.o)

#Targets
$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
