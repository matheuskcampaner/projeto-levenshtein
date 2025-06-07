CC = gcc
CFLAGS = -Wall -I/usr/include/lua5.4
LIBS = -llua5.4 -lm

SRC = src/main.c src/levenshtein.c
OUT = projeto

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LIBS)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)