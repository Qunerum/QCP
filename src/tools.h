#ifndef TOOLS_H
#define TOOLS_H

static inline int len(char* text) { char* start = text; while (*text) { text++; } return (int)(text - start); }
static inline int is(char* a, char* b) { while (*a != '\0' && *b != '\0') { if (*a != *b) return 0; a++; b++; } return (*a == *b); }
static inline int startWith(char* text, char* start) { while (*start != '\0') { if (*text == '\0' || *text != *start) return 0; text++; start++; } return 1; }
static inline void moveLeft(char* text, int n) { int l = len(text), i = 0; while (i < l - n) { text[i] = text[i + n]; i++; } text[l - n] = '\0';}
static inline void trimStart(char* text, char c) { int s = 0; while (text[s] && text[s] == c) s++; moveLeft(text, s); }

#endif
