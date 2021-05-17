#include "Main.h"

void print_number(unsigned int counter){
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

void print_line(unsigned short width){
    for (unsigned short i = 0; i < width; i++)
        printf("-");
    NEW_LINE();
}

int main(int argc, char **argv) {
    //printf("\n%s\n", argv[1]);

    // amount of chars in single string
    const unsigned short MAXCHAR = 1000;
    // detecting width of terminal
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const unsigned short WIDTH = w.ws_col;


    // opening file for reading
    FILE* file;
    char str[MAXCHAR];
    // filename is first argument of executing
    char* filename = argv[1];
    file = fopen(filename, "r");
    //checking for file existing
    if (file == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }


    // drawing line
    print_line(WIDTH);
    // printing file name
    MV_RIGHT(8);
    STD_OFFSET();
    printf("File: %s%s%s", BOLD, filename, STANDART);
    printf("\n");
    // drawing lines
    print_line(WIDTH);


    // counter of strings   
    unsigned int counter = 1;
    while (fgets(str, MAXCHAR, file) != NULL) {
        print_number(counter);
        STD_OFFSET();
        printf("%s", str);
        counter++;
    }

    NEW_LINE();
    print_line(WIDTH);


    fclose(file);

    return 0;
}