#define _POSIX_C_SOURCE 200809L

#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

#define SERV_PORT 9877

#define LISTENQ 1024
#define MAXLINE 4096 /* max text line length */

/* Define bzero() as a macro if it's not in standard C library. */
#ifndef HAVE_BZERO
#define bzero(ptr, n) memset(ptr, 0, n)
#endif

/* Following shortens all the type casts of pointer arguments */
#define SA struct sockaddr

#if defined(__x86_64__) || defined(_M_X64)
#define HOST_CPU "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
#define HOST_CPU "i686"
#elif defined(__aarch64__)
#define HOST_CPU "aarch64"
#else
#define HOST_CPU "unknown"
#endif

#if defined(__linux__)
#define HOST_OS "linux-gnu"
#elif defined(__APPLE__)
#define HOST_OS "darwin"
#elif defined(_WIN32)
#define HOST_OS "windows"
#else
#define HOST_OS "unknown"
#endif

#define CPU_VENDOR_OS HOST_CPU "-pc-" HOST_OS

typedef void Sigfunc(int); /* for signal handlers */

char *Sock_ntop(const SA *, socklen_t);

char *Fgets(char *, int, FILE *);
void Fputs(const char *, FILE *);

int Socket(int, int, int);
void Bind(int, const SA *, socklen_t);
void Connect(int, const SA *, socklen_t);
void Listen(int, int);
int Accept(int, SA *, socklen_t *);
void Write(int, void *, size_t);
void Writen(int, void *, size_t);
ssize_t Readn(int, void *, size_t);
ssize_t Readline(int, void *, size_t);
void Close(int);

pid_t Fork(void);

void str_echo(int);
void str_cli(FILE *, int);

const char *Inet_ntop(int, const void *, char *, size_t);
void Inet_pton(int, const char *, void *);

void err_quit(const char *, ...);
void err_sys(const char *, ...);