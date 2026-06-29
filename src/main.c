#include <stdio.h>
#include "compiler.h"

int main() {
    FILE* in = fopen("test.qcp", "r");
    if (!in) { printf("Cannot open the file!\n"); return 1; }
    startCompiler();
    char line[1024];

    while (fgets(line, sizeof(line), in)) {
        printf(": %s", line);
    }

    fclose(in);
    endCompiler();
    return 0;
}
