#include "Main.h"

// amount of chars in single string
const unsigned short MAXCHAR = 1000;

unsigned short 
language(char* file){
    /*
        0 - txt
        1 - c
        2 - c++
        3 - python
        4 - shell
    */
    char delim = '.';
    char *ext = strtok(file, &delim);
    ext = strtok(NULL, &delim);
    
    printf("%s\n", ext);
    if (strcmp(ext, C) != 0)
        return 1;
    else if (strcmp(ext, CPP) != 0)
        return 2;
    else if (strcmp(ext, PYTHON) != 0)
        return 3;
    else if (strcmp(ext, SHELL) != 0)
        return 4;
    else if (strcmp(ext, TEXT) != 0)
        return 0;
    else
        return 0;
}

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

void 
print_line(unsigned short width){
    for (unsigned short i = 0; i < width; i++)
        printf("-");
    NEW_LINE();
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
    char str[MAXCHAR];
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
    int length = strlen(filename);
    char extension[length];
    for (int i = 0; i < length; i++)
        extension[i] = filename[i];
    extension[length] = ' ';
    const unsigned short LANG = language(filename);
    NEW_LINE();

    //WERROR
    printf("%d\n", LANG);

    // drawing line
    print_line(WIDTH);
    // printing file name
    MV_RIGHT(8);
    STD_OFFSET();
    printf("File: %s%s%s", BOLD, extension, STANDART);
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