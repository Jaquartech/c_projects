# # CC = gcc
# # CFLAGS = -Wall -Wextra -Werror -std=gnu99

# # INCDIR = libc_library_functions/include
# # BINDIR = libc_library_functions/bin
# # SRCDIR = libc_library_functions/src
# # OBJDIR = libc_library_functions/obj

# # INCLUDE = -I./$(INCDIR)
# # SRCS = $(wildcard $(SRCDIR)/*.c)
# # OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# # EXECUTABLE = $(BINDIR)/main

# # all: $(EXECUTABLE)
# # 	@echo "Build successful"

# # $(EXECUTABLE): $(OBJS)
# # 	$(CC) $^ -o $@
# # 	@echo "linking successful..."

# # $(OBJDIR)/%.o: $(SRCDIR)/%.c
# # 	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
# # 	@echo "Compilation of .o files successful..."

# # clean:
# # 	rm -f $(OBJDIR)/*.o $(BINDIR)/main
# # 	@echo "cleaning $(OBJDIR)/*.o and $(EXECUTABLE) files..."


# # Directories
# INC_DIRS = -I./data_structures/array/include -I./libc_library_functions/include
# SRC_DIRS = data_structures/array/src libc_library_functions/src
# OBJ_DIR = objects
# DEP_DIR = dependencies
# EXE_DIR = executables

# # executables
# EXECUTABLE = $(EXE_DIR)/main

# # C flags
# CC = gcc
# ENABLE_WARNING = -Wall -Wextra -Werror
# OPT = -O0
# C_STANDARD = -std=gnu99
# DEP = -MP -MD
# CFLAGS = $(ENABLE_WARNING) -c $(C_STANDARD) $(OPT) $(DEP) $(INC_DIRS)

# # Source Variables
# SOURCES = $(foreach D, $(SRC_DIRS), $(wildcard $(D)/*.c))

# # Object Variables
# OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

# # Dependency Variables
# DEP_FILES = $(patsubst %.c, $(DEP_DIR)/%.d, $(SOURCES))

# # binary target
# all: $(EXECUTABLE)

# OBJ_DIRS := $(foreach D, $(SRC_DIRS), $(OBJ_DIR)/$(D))


# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $^ -o $@

# $(OBJ_DIR)/%.o: %.c | $(OBJ_DIRS)
# 	$(CC) $(CFLAGS) $< -o $@

# $(OBJ_DIRS):
# 	@mkdir -p $(OBJ_DIRS)

# # Dependency file creation rule
# $(DEP_DIR)/%.d: %.c | $(DEP_DIR)
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) -MM $< > $@
# 	@echo "Dependency file generated for $<"

# # $(DEP_DIR)/%.d: | $(DEP_DIR)
# # 	@mkdir -p $(DEP_DIR)

# -include $(DEP_FILES)

# # Clean up
# clean:
# 	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)
# 	rm -f $(DEP_DIR)/*.d
# 	@echo "cleaning $(OBJ_DIR)/*.o, $(DEP_DIR)/*.d, and $(EXECUTABLE) files..."

# Directories
INC_DIRS = -I./data_structures/array/include -I./libc_library_functions/include -I./data_structures/list/include
SRC_DIRS = data_structures/array/src data_structures/list/src .
OBJ_DIR = objects
DEP_DIR = dependencies
EXE_DIR = executables

# Executable
EXECUTABLE = $(EXE_DIR)/main

# C flags
CC = gcc
ENABLE_WARNING = -Wall -Wextra -Werror
OPT = -O0
C_STANDARD = -std=gnu99
DEP = -MP -MD
CFLAGS = $(ENABLE_WARNING) -c $(C_STANDARD) $(OPT) $(DEP) $(INC_DIRS)

# Source Variables
SOURCES = $(foreach D, $(SRC_DIRS), $(wildcard $(D)/*.c))

# Object Variables
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Dependency Variables
DEP_FILES = $(patsubst %.c, $(DEP_DIR)/%.d, $(SOURCES))

# Create directories for object files
OBJ_DIRS := $(foreach D, $(SRC_DIRS), $(OBJ_DIR)/$(D))

# Binary target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) | $(EXE_DIR)
	$(CC) $^ -o $@

# Object file creation rule
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Create object directories
$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)

# Ensure the executables directory exists
$(EXE_DIR):
	@mkdir -p $(EXE_DIR)

# Dependency file creation rule
$(DEP_DIR)/%.d: %.c | $(DEP_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MM $< > $@
	@echo "Dependency file generated for $<"

-include $(DEP_FILES)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR) $(EXECUTABLE)
	@echo "cleaning $(OBJ_DIR), $(DEP_DIR), and $(EXECUTABLE) files..."

