#include <stdio.h>
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

// color scheme
#define VAR_TYPE        "\x1B[38;5;26m"    
#define STR_LITERAL     "\x1B[38;5;208m"
#define ESCAPE_CHAR     "\x1B[38;5;215m"
#define STD_RESEVED     "\x1B[38;5;201m"

void
print_number(unsigned int counter);