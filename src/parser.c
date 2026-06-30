#include "tools.h"
#include "main.h"
#include <stdio.h>

int inFunction = 0, inString = 0;
extern struct QCP_Node* root;
struct QCP_Node* actualFunc;
void madeLine(char line[MAX_LINE_SIZE]) {
	int l = len(line);
	if (line[l-1] == '\n') line[l-1] = '\0';
	trimStart(line, ' '); trimStart(line, '\t');
	printf("'%s'\n", line);
	if (startWith(line, "func")) {
		struct QCP_Node* fn = createNode(QCP_FUNC, "test", "");
		actualFunc = fn;
		addChild(root, fn);
	}

}
