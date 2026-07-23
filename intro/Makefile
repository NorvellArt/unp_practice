# Компилятор и флаги (-I../lib указывает путь к unp.h)
CC = gcc
CFLAGS = -Wall -Wextra -I../lib

LIB_SRC = ../lib/error.c ../lib/wrappthread.c ../lib/wrapsock.c  ../lib/wrapunix.c 

PROGS =	daytimetcpcli daytimetcpcliv6 daytimetcpsrv

# Дефолтная цель: собираем программу
all: $(PROGS)

# Сборка клиенского файла вместе с ошибками из lib/
daytimetcpcli: daytimetcpcli.c $(LIB_SRC)
	$(CC) $(CFLAGS) $^ -o $@
daytimetcpcliv6: daytimetcpcliv6.c $(LIB_SRC)
	$(CC) $(CFLAGS) $^ -o $@
daytimetcpsrv: daytimetcpsrv.c $(LIB_SRC)
	$(CC) $(CFLAGS) $^ -o $@

# Очистка скомпилированного бинарника
clean:
	rm -f $(PROGS)

.PHONY: all clean