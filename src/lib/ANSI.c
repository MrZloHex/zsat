#include "ANSI.h"

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