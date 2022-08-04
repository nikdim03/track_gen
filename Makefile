CC = gcc
Files = gen.c
CFlags = -g -Wall -Werror -Wextra

all:
	@make build

build:
	@$(CC) $(CFlags) $(Files)

clean:
	@rm -rf *.out
	@rm -rf *.dSYM

rebuild:
	@make clean
	@make
