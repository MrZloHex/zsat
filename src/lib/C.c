#include "C.h"

void
c_lang(char *filename) {
    FILE *file;
    file = fopen(filename, "r");

    fclose(file);
}