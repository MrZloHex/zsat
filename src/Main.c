// include libraries
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>

// defining supporting languages
#define TEXT            0
#define C               1
#define CPP             2
#define PYTHON          3
#define SHELL           4
#define JAVA            5

// escape sequances
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

#define NEW_LINE()      printf("\n")
#define STD_OFFSET()    printf("|\x1B[2C")

// amount of chars in single string
const unsigned short MAXCHAR = 1000;

void 
print_number(unsigned int counter){
    printf("%s%s", ITALIC, DIM);
    if (counter < 10) {
        MV_RIGHT(5);
        printf("%d", counter);
        MV_RIGHT(2);
    }
    else if (counter < 100) {
        MV_RIGHT(4);
        printf("%d", counter);
        MV_RIGHT(2);
    }
    else if (counter < 1000) {
        MV_RIGHT(3);
        printf("%d", counter);
        MV_RIGHT(2);
    }
    else if (counter < 10000) {
        MV_RIGHT(2);
        printf("%d", counter);
        MV_RIGHT(2);
    }
    printf("%s", STANDART);
}

unsigned short 
language(char* file){
    /*
        0 - txt
        1 - c
        2 - c++
        3 - python
        4 - shell
        5 - java
    */
    char delim = '.';
    char *ext = strchr(file, delim);
    // not to detect dot
    ext += 1;
    if ((strcmp(ext, "c") == 0) || (strcmp(ext, "h") == 0))
        return 1;
    else if ((strcmp(ext, "cpp") == 0) || (strcmp(ext, "hpp") == 0))
        return 2;
    else if ((strcmp(ext, "py") == 0) || (strcmp(ext, "pyd") == 0) ||
             (strcmp(ext, "pyo") == 0) || (strcmp(ext, "pyc") == 0))
        return 3;
    else if ((strcmp(ext, "sh") == 0) || (strcmp(ext, "bash") == 0) ||
             (strcmp(ext, "zsh") == 0) || (strcmp(ext, "csh") == 0))
        return 4;
    else if ((strcmp(ext, "java") == 0))
        return 5;
    else if (strcmp(ext, "txt") == 0)
        return 0;
    else
        return 0;
}


void 
print_line(unsigned short width){
    for (unsigned short i = 0; i < width; i++)
        printf("-");
    NEW_LINE();
}


void
print_lang(unsigned short lang) {
    printf("%s", BOLD);
    if (lang == TEXT) {
        printf("Text");
        MV_RIGHT(3);
    }
    else if (lang == C) {
        printf("C");
        MV_RIGHT(6);
    }
    else if (lang == CPP) {
        printf("C++");
        MV_RIGHT(4);
    }
    else if (lang == PYTHON) {
        printf("Python");
        MV_RIGHT(1);
    }
    else if (lang == SHELL) {
        printf("Shell");
        MV_RIGHT(2);
    }
    else if (lang == JAVA) {
        printf("Java");
        MV_RIGHT(3);
    }
    else {
        printf("Text");
        MV_RIGHT(3);
    }
    printf("%s", STANDART);
}



int 
main(int argc, char **argv) {
    //printf("\n%s\n", argv[1]);
    //for WERROR
    printf("%s%d%s",INVISIBLE, argc, STANDART);
    MV_LEFT(1);

    // detecting width of terminal
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const unsigned short WIDTH = w.ws_col;
    // opening file for reading
    FILE* file;
    // filename is first argument of executing
    char* filename = argv[1];
    file = fopen(filename, "r");
    //checking for file existing
    if (file == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    // detecting extencion and programming language
    /*
        0 - c
        1 - c++
        2 - python
        3 - shell
    */
    const unsigned short LANG = language(filename);


    
    // drawing line
    print_line(WIDTH);
    // printing lang
    MV_RIGHT(1);
    print_lang(LANG);
    // printing file name
    STD_OFFSET();
    printf("File: %s%s%s", BOLD, filename, STANDART);
    printf("\n");
    // drawing lines
    print_line(WIDTH);

    char str[MAXCHAR];
    unsigned int counter = 1;
    while (fgets(str, MAXCHAR, file) != NULL) {
        print_number(counter);
        STD_OFFSET();
        printf("%s", str);
        counter++;
    }

    NEW_LINE();
    print_line(WIDTH);

    return 0;
}