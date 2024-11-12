# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Target executable
TARGET = executaveis/algorithm

# Source files
SRCS = main.c algorithm.c

# Object files
OBJS = $(SRCS:%.c=executaveis/%.o)

# Build directory
BUILD_DIR = executaveis

# Default target
all: $(BUILD_DIR) $(TARGET)

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
executaveis/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Para executar o programa:
run:
	./$(TARGET)

#manualmente, insira "./executaveis/algorithm" no terminal