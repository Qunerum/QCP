#include "tools.h"
#include "main.h"
#include <stdio.h>

int lnNmb = 1, deep = 0, inString = 0;
extern struct QCP_Node* root;
struct QCP_Node* actualFunc;
void madeLine(char line[MAX_LINE_SIZE]) {
	int l = len(line);
	if (line[l-1] == '\n') line[l-1] = '\0';
	trimStart(line, ' '); trimStart(line, '\t');
	// printf("'%s'\n", line);
	char list[16][256];
	int max = split(line, ' ', list);
	if (max <= 0) return;
	printf("[");
	for (int i = 0; i < max; i++) {
		printf("'%s', ", list[i]);
	}
	printf("\b\b] Length: %d\n", max);

	if (is(list[0], "func") && deep == 0) {
		deep++;
		char name[256];
		char args[1024];
		int argLen = 0;
		splitSimple(list[1], '(', name, args, NULL, &argLen);
		if (args[argLen - 1] == ')') {
			args[argLen - 1] = '\0';
			printf("Args: '%s'\n", args);
		} else err(lnNmb, line, EXPECTED);


		// struct QCP_Node* fn = createNode(QCP_FUNC, "test", "");
		// actualFunc = fn;
		// addChild(root, fn);
	}
	lnNmb++;
}
