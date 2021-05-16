#include <stdio.h>
 
#define MAXCHAR 1000

int main() {
    FILE *file;
    char str[MAXCHAR];
    char* filename = "file_for_test.c";
 
    file = fopen(filename, "r");

    if (file == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    while (fgets(str, MAXCHAR, file) != NULL)
        printf("%s", str);

    fclose(file);
    printf("\n%s\n", str);

    return 0;
}