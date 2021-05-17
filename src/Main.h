#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

#define ESC             "\x1B"

#define STADART             "\x1B[0m"
#define BOLD                "\x1B[1m"
#define DIM                 "\x1B[2m"
#define ITALIC              "\x1B[3m"
#define UNDERLINE           "\x1B[4m"
#define BLINK               "\x1B[5m"

#define FUN_MV_UP(i)        printf("\x1B[%dA", (i))
#define FUN_MV_DOWN(i)      printf("\x1B[%dB", (i))
#define FUN_MV_RIGHT(i)     printf("\x1B[%dC", (i))
#define FUN_MV_LEFT(i)      printf("\x1B[%dD", (i))

