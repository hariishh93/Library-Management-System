CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -g

TARGET = library

SRC = \
globals.c \
lib_main.c \
add_book.c \
upd_book.c \
rem_book.c \
srch_book.c \
allv_book.c \
issue_book.c \
ret_book.c \
list_ised_book.c \
save_book.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c library.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
