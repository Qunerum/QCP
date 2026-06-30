#include <stdio.h>
#include <stdlib.h>
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
    struct QCP_Node* main = createNode(QCP_FUNC, "main", "");
    addChild(root, main);
    struct QCP_Node* int_x = createNode(QCP_LOCAL_INT, "x", "15");
    struct QCP_Node* int_y = createNode(QCP_LOCAL_INT, "y", "5");
    addChild(main, int_x);
    addChild(main, int_y);

    char line[MAX_LINE_SIZE];
    while (fgets(line, sizeof(line), in)) { madeLine(line); }
    fclose(in);
    printf("\nPrinting tree:\n");
    printTree(root, 0);
    printf("\n\n");

    return endCompiler();
}

struct QCP_Node* createNode(QCP_Node_Type type, char* name, char* value) {
    struct QCP_Node* newNode = malloc(sizeof(struct QCP_Node));
    newNode->type = type;
    newNode->name = name;
    newNode->value = value;
    newNode->child = NULL;
    newNode->next = NULL;
    return newNode;
}
void addChild(struct QCP_Node* parent, struct QCP_Node* newChild) {
    if (parent->child == NULL) parent->child = newChild; else {
        struct QCP_Node* temp = parent->child;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newChild;
    }
}
