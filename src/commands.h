#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct {
	char* lineTemp;
	void (*handler)(char**);
} QCP_Command;

#endif
