#ifndef MAIN_H
#define MAIN_H

typedef struct { char* cmd; void (*handler)(char*); } qcpCmd;
typedef struct { int type; char* name; char* value; } qcpVar;
typedef struct { char* name; char* data; } qcpFunc;

#endif
