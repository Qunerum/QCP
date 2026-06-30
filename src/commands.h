#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct {
	char* lineTemp;
	void (*handler)(char**);
} QCP_Command;

extern QCP_Command cmds[];
extern int cmdCount;

#endif
