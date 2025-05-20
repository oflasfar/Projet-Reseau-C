# Nom de l'exécutable final
TARGET = bin/main

# Répertoires
SRC_DIR = src
INC_DIR = $(SRC_DIR)/include
BUILD_DIR = build

# Fichiers sources et objets
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/reseau.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -I$(INC_DIR)
LDFLAGS = # -fsanitize=address

# Cible principale
all: $(TARGET)

# Edition de liens
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compilation des .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean

