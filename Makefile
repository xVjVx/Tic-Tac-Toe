tictactoe: tictactoe.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf tictactoe

all: tictactoe
