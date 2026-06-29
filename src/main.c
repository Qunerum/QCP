#include <stdio.h>
#include "main.h"
#include "parser.h"
#include "compiler.h"

int main() {
    FILE* in = fopen("test.qcp", "r");
    if (!in) { printf("Cannot open the file!\n"); return 1; }
    struct QCP_Node* root = startCompiler();
    char line[MAX_LINE_SIZE];

    while (fgets(line, sizeof(line), in)) {
        // printf(": %s", line);
        madeLine(line);
    }

    fclose(in);
    endCompiler();
    return 0;
}
