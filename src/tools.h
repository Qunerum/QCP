#ifndef TOOLS_H
#define TOOLS_H

static inline int len(char* text) { int i = 0; while(text[i]) i++; return i; }
static inline void moveLeft(char* text, int n) { int l = len(text), i = 0; while (i < l - n) { text[i] = text[i + n]; i++; } text[l - n] = '\0';}
static inline void trimStart(char* text, char c) { int s = 0; while (text[s] && text[s] == c) s++; moveLeft(text, s); }

#endif
