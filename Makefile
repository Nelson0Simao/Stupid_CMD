CC = gcc
CFLAGS = -Wall
TARGET = build/exe
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
INCLUDE_DIR = include
DOC_DIR = docs
TEST_DIR = tests

all: directories $(TARGET) update_readme

$(TARGET): $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$<

clean:
	rm -rf build obj

.PHONY: all run clean update_readme directories

update_readme:
	@echo 'Atualizando README.md com o número de diretórios...'
	@echo '' >> README.md
	@echo '## Número de Diretórios' >> README.md
	@echo '' >> README.md
	@echo 'O projeto contém $$(shell find . -type d -not -path '*/.*' | wc -l) diretórios.' >> README.md

directories: $(LIB_DIR) $(INCLUDE_DIR) $(OBJ_DIR) $(DOC_DIR) $(TEST_DIR)

$(LIB_DIR) $(INCLUDE_DIR) $(OBJ_DIR) $(DOC_DIR) $(TEST_DIR):
	mkdir -p $@

