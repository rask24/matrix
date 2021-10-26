CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic-errors
AR = ar
ARFLAGS = rc
SRCDIR = src
SRCS =	$(SRCDIR)/constructor.cpp \
		$(SRCDIR)/operator.cpp \
		$(SRCDIR)/dev.cpp \
		$(SRCDIR)/getter.cpp \
		$(SRCDIR)/utils.cpp \
		$(SRCDIR)/setter.cpp \
		$(SRCDIR)/square.cpp
OBJS = $(SRCS:.cpp=.o)
TRG = matrix.a
MAIN = main.cpp
EXE = matrix_main

all: $(TRG)

$(TRG): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(EXE): $(MAIN) $(TRG)
	$(CC) $< $(TRG) -o $(EXE)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@ -I ./

test: $(EXE)

leaks: $(MAIN) $(TRG)
	$(CC) $< $(TRG) -D LEAKS -o $(EXE)

run: $(EXE)
	./$(EXE)

clean:
	$(RM) $(OBJS) $(TRG) $(EXE)

re: clean all

.PHONY: all clean test leaks run re
