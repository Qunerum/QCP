#ifndef MAIN_H
#define MAIN_H

typedef enum {  } QCP_Node_Type;
typedef struct {
	QCP_Node_Type type;
	char* name;
	char* value;
} QCP_Node;

#endif
