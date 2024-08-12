CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=gnu99

INCDIR = libc_library_functions/include
BINDIR = libc_library_functions/bin
SRCDIR = libc_library_functions/src
OBJDIR = libc_library_functions/obj

INCLUDE = -I./$(INCDIR)
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
