#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

#define STADART     "\x1B[0m"
#define BOLD        "\x1B[1m"
#define DIM         "\x1B[2m"
#define ITALIC      "\x1B[3m"
#define UNDERLINE   "\x1B[4m"
#define BLINK       "\x1B[5m"