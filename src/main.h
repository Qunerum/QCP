#ifndef MAIN_H
#define MAIN_H

#define MAX_LINE_SIZE 4096

typedef enum { QCP_ROOT, QCP_FUNC } QCP_Node_Type;
struct QCP_Node {
	QCP_Node_Type type;
	char* name;
	char* value;
	struct QCP_Node* child;
	struct QCP_Node* next;
};

#endif
