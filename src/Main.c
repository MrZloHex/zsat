#include "Main.h"


void print_line(unsigned short width){
    for (unsigned short i = 0; i < width; i++)
        printf("-");
}

int main(int argc, char **argv) {
    //printf("\n%s\n", argv[1]);

    // counter of strings   
    unsigned int counter = 0;
    // amount of chars in single string
    const unsigned short MAXCHAR = 1000;
    // detectting width of terminal
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const unsigned short WIDTH = w.ws_col;

    // opening file for reading
    FILE *file;
    char str[MAXCHAR];
    // filename is first argument of executing
    char* filename = argv[1];
    file = fopen(filename, "r");
    //checking for file existing
    if (file == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    // drawing lines
    print_line(WIDTH);
    // printing file name
    printf("        |  File: \x1B[1m%s\x1B[0m", filename);
    printf("\n");
    // drawing lines
    print_line(WIDTH);



    while (fgets(str, MAXCHAR, file) != NULL) {
        counter++;

        if (counter < 10)
            printf("     %d  |", counter);
        else if (counter < 100)
            printf("    %d  |", counter);
        else if (counter < 1000)
            printf("   %d  |", counter);
        else if (counter < 10000)
            printf("  %d  |", counter);
        
        printf("  %s", str);
    }

    printf("\n");
    print_line(WIDTH);


    fclose(file);
    printf("\n");

    return 0;
}