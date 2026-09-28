CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -g
TARGET = personagens

SRCS = main.c personagem.c interface.c inventario.c item.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
