#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define MAXLINE 4096 /* max text line length */

/* Define bzero() as a macro if it's not in standard C library. */
#ifndef HAVE_BZERO
#define bzero(ptr, n) memset(ptr, 0, n)
#endif

/* Following shortens all the type casts of pointer arguments */
#define SA struct sockaddr

int Socket(int, int, int);

void err_quit(const char *, ...);
void err_sys(const char *, ...);