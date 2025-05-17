CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o account.o data.o transactions.o utils.o
TARGET = bank_system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
