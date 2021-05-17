#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

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
    for (unsigned short i = 0; i < WIDTH; i++)
        printf("-");
    // printing file name
    printf("        |\t%s", filename);
    printf("\n");
    // drawing lines
    for (unsigned short i = 0; i < WIDTH; i++)
        printf("-");



    while (fgets(str, MAXCHAR, file) != NULL) {
        counter++;
        printf("%d\t%s", counter, str);
    }



    fclose(file);
    printf("\n");

    return 0;
}