all:
	clang-3.5 -pthread -o test main.c queue.c

clean:
	rm -f test
