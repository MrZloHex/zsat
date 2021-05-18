// include libraries
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>
// include files to color backlight
#include "lib/C.h"
#include "lib/CPP.h"
#include "lib/PYTHON.h"
#include "lib/SHELL.h"
#include "lib/TEXT.h"
// ANSI escapes
#include "lib/ANSI.h"

// defining supporting languages
#define TEXT            0
#define C               1
#define CPP             2
#define PYTHON          3
#define SHELL           4