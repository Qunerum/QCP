#ifndef MAIN_H
#define MAIN_H

typedef struct {
    char* cmd;
    void (*handler)(char*);
} qcCmd;
typedef struct {
    int type;
    char* name;
    char* value;
} qcVar;
typedef struct {
    char* name;
    char* data;
} qcFunc;



#endif
