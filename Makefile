main: main.c data.c board_io.c movement.c
	cc main.c data.c board_io.c movement.c -o main

clean:
	rm main
