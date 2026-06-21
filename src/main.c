#include <stdio.h>
#include "../include/memory.h"

int main() {
    init_memory();
    FILE* file = fopen("test.qcp", "r");
    if (!file) { printf("Cannot open a file!\n"); return 1; }
    int symbol, c;
    while ((symbol = fgetc(file)) != EOF) {
        if (symbol == '\n') continue;
        else if (symbol == '{') { c++; continue; }
        else if (symbol == '}' && c > 0) { c--; continue; }
    }
    printf("%d", c);
    fclose(file);
    putchar(10);
    return 0;
}
