CC = gcc
CFLAGS = -std=c11 -D_POSIX_C_SOURCE=199309L -Wall -O2 -Isrc/c
NASM = nasm
NASMFLAGS = -f elf64

SRC_C = src/c/main.c src/c/csv.c src/c/bubble_sort.c
SRC_ASM = src/asm/bubble_sort.asm
OBJ_ASM = src/asm/bubble_sort.o
OUT = asmsort

all: $(OBJ_ASM)
	$(CC) $(CFLAGS) $(SRC_C) $(OBJ_ASM) -o $(OUT)

$(OBJ_ASM): $(SRC_ASM)
	$(NASM) $(NASMFLAGS) $(SRC_ASM) -o $(OBJ_ASM)

clean:
	rm -f $(OUT) $(OBJ_ASM)