# Компилятор и флаги (-I../lib указывает путь к unp.h)
CC = gcc
CFLAGS = -Wall -Wextra -I../lib

LIB_SRC = ../lib/error.c ../lib/wrappthread.c ../lib/wrapsock.c  ../lib/wrapunix.c \
		../lib/sock_ntop.c ../lib/writen.c ../lib/readn.c ../lib/readline.c ../lib/str_echo.c \
		../lib/wraplib.c ../lib/wrapstdio.c ../lib/str_cli.c ../lib/signal.c

PROGS =	tcpserv01 tcpcli01

all: $(PROGS)

tcpserv01: tcpserv01.c $(LIB_SRC)
	$(CC) $(CFLAGS) $^ -o $@
tcpcli01: tcpcli01.c $(LIB_SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(PROGS)

.PHONY: all clean