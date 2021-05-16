#include <stdio.h>
 
#define MAXCHAR 1000

int main(int argc, char **argv) {
    //printf("\n%s\n", argv[1]);

    FILE *file;
    char str[MAXCHAR];
    char* filename = argv[1];
 
    file = fopen(filename, "r");

    if (file == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    while (fgets(str, MAXCHAR, file) != NULL)
        printf("%s", str);

    fclose(file);
    printf("\n");

    return 0;
}