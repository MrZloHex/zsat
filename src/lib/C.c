#include "C.h"

void
analys_str(char str[1000]){
    printf("%s%s%s", STD_RESEVED, str, STANDART);
}


void
c_lang(char *filename) {
    FILE *file;
    file = fopen(filename, "r");

    char str[1000];
    unsigned int counter = 1;
    while (fgets(str, 1000, file) != NULL) {
        print_number(counter);
        STD_OFFSET();
        analys_str(str);
        counter++;
    }

    fclose(file);
}