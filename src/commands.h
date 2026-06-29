#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct {
	char* cmd;
	void (*handler)(char**);
} QCP_Command;

#endif
