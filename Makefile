NAME    ?= out
CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -std=c11 -MMD -MP
LDLIBS  := -lm -pthread
# default source
SRC_DIR := src
OBJ_DIR := objs
SRC     := $(wildcard $(SRC_DIR)/*.c)
# src/main.c > objs/main.o
OBJ     := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEPS    := $(OBJ:.o=.d)
# for DEBUG by default 1
DEBUG ?= 1
ifeq ($(DEBUG),1)
	CFLAGS += -g -Og -DDEBUG
else
	CFLAGS += -O2
endif

.PHONY: all build run clean

all: build

build: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: build
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR) $(NAME)

-include $(DEPS)
