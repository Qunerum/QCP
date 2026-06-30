#include <stdio.h>
#include "main.h"
#include "parser.h"
#include "compiler.h"

void printTree(struct QCP_Node* node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("- Type: '%d', Name: '%s', Value: '%s'\n", node->type, node->name, node->value);
    printTree(node->child, depth + 1);
    printTree(node->next, depth);
}

int main() {
    FILE* in = fopen("test.qcp", "r");
    if (!in) { printf("Cannot open the file!\n"); return 1; }
    struct QCP_Node* root = startCompiler();
    if (root == NULL) return 1;
    char line[MAX_LINE_SIZE];
    while (fgets(line, sizeof(line), in)) { madeLine(line); }
    fclose(in);
    printf("\nPrinting tree:\n");
    printTree(root, 0);
    printf("\n\n");

    return endCompiler();
}
