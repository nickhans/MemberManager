CC = g++
CFLAGS = -Wall -Wextra -pedantic -Wconversion
PROG = MemberManager
SRC = main.cpp member.cpp inout.cpp
HDR = member.h inout.h
OBJ = $(SRC:.cpp=.o)

#Targets
$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
