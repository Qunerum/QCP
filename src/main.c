#include <stdio.h>
#include "../include/memory.h"

int main() {
    init_memory();
    FILE* file = fopen("test.qcp", "r");
    if (!file) {
        printf("Cannot open a file!\n");
        return 1;
    }

    int symbol;
    while ((symbol = fgetc(file)) != EOF) {
        if (symbol != '\n') putchar(symbol);
    }
    fclose(file);
    putchar(10);
    return 0;
}
