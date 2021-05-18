// include libraries
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>
// include files to color backlight
#include "lib/C.h"

// defining supporting languages
#define TEXT            0
#define C               1
#define CPP             2
#define PYTHON          3
#define SHELL           4

// defining ANSI escapes
#define ESC             "\x1B"

#define STANDART            "\x1B[0m"
#define BOLD                "\x1B[1m"
#define DIM                 "\x1B[2m"
#define ITALIC              "\x1B[3m"
#define UNDERLINE           "\x1B[4m"
#define BLINK               "\x1B[5m"
#define INVISIBLE           "\x1B[8m"

#define MV_UP(i)        printf("\x1B[%dA", (i))
#define MV_DOWN(i)      printf("\x1B[%dB", (i))
#define MV_RIGHT(i)     printf("\x1B[%dC", (i))
#define MV_LEFT(i)      printf("\x1B[%dD", (i))

#define NEW_LINE()      printf("\n");
#define STD_OFFSET()    printf("|\x1B[2C")

