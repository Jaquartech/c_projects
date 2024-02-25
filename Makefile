CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=gnu99

INCDIR = include
BINDIR = bin
SRCDIR = src
OBJDIR = obj

INCLUDE = -I./$(BINDIR)
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
EXECUTABLE = $(BINDIR)/main

all: $(EXECUTABLE)
	@echo "Build successful"

$(EXECUTABLE): $(OBJS)
	$(CC) $^ -o $@
	@echo "linking successful..."

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "Compilation of .o files successful..."

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/main
	@echo "cleaning $(OBJDIR)/*.o and $(EXECUTABLE) files..."
