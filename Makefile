CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
SRCDIR = src
OBJDIR = obj
BINDIR = build
INCDIR = include
TARGET = $(BINDIR)/my_shell
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

.PHONY: clean

run:
	./$(TARGET)

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/*

