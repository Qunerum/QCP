#ifndef COMMANDS_H
#define COMMANDS_H
#include "main.h"

typedef struct {
	char* cmd;
	void (*handler)(char list[16][256]);
} QCP_Command;

extern QCP_Command cmds[];
extern int cmdCount;
void runCmd(char list[16][256], char _line[MAX_LINE_SIZE]);

#endif
