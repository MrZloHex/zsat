#include "C.h"

void
c_lang(char *filename) {
    FILE *file;
    file = fopen(filename, "r");

    char str[1000];
    unsigned int counter = 1;
    while (fgets(str, 1000, file) != NULL) {
        print_number(counter);
        STD_OFFSET();
        printf("%s", str);
        counter++;
    }

    fclose(file);
}