#include <stdlib.h>
#include <stdio.h>
#include "main.h"

FILE* out;
struct QCP_Node* root;
struct QCP_Node* startCompiler() {
	out = fopen("out.asm", "w");
	if (!out) { printf("Cannot open/write a file!\n"); return NULL; }

	root = malloc(sizeof(struct QCP_Node));
	root->type = QCP_ROOT;
	root->name = "root";
	root->value = "";
	root->child = NULL;
	root->next = NULL;

	fprintf(out, "default rel\n");
	fprintf(out, "; = = = = = = = = = = VARIABLES = = = = = = = = = =\n");
	fprintf(out, "section .data\n");
	fprintf(out, "\tnl db 10\n");
	fprintf(out, "\tnll equ $ - nl\n");
	fprintf(out, "section .bss\n");
	fprintf(out, "\tbufor resb 12\n");
	fprintf(out, "; = = = = = = = = = = INT TO TEXT = = = = = = = = = =\n");
	fprintf(out, "section .text\n");
	fprintf(out, "\tglobal _start\n");
	fprintf(out, "intToText:\n");
	fprintf(out, "\tmov rcx, 0\n");
	fprintf(out, "\tmov ebx, 10\n");
	fprintf(out, ".ittLoop:\n");
	fprintf(out, "\tmov edx, 0\n");
	fprintf(out, "\tdiv ebx\n");
	fprintf(out, "\tadd edx, 48\n");
	fprintf(out, "\tpush rdx\n");
	fprintf(out, "\tinc rcx\n");
	fprintf(out, "\tcmp eax, 0\n");
	fprintf(out, "\tjne .ittLoop\n");
	fprintf(out, "\tlea rdi, [rel bufor]\n");
	fprintf(out, "\tmov rdx, rcx\n");
	fprintf(out, "\tlea rsi, [rel bufor]\n");
	fprintf(out, ".ittLoopWrite:\n");
	fprintf(out, "\tpop rax\n");
	fprintf(out, "\tmov [rdi], al\n");
	fprintf(out, "\tinc rdi\n");
	fprintf(out, "\tloop .ittLoopWrite\n");
	fprintf(out, "\tinc rdx\n");
	fprintf(out, "\tret\n");
	fprintf(out, "; = = = = = = = = = = PRINT = = = = = = = = = =\n");
	fprintf(out, "prt:\n");
	fprintf(out, "\tmov rax, 1\n");
	fprintf(out, "\tmov rdi, 1\n");
	fprintf(out, "\tsyscall\n");
	fprintf(out, "\tret\n");
	fprintf(out, "; = = = = = = = = = = FUNCTIONS = = = = = = = = = =\n");
	// print all functions
	fprintf(out, "; = = = = = = = = = = MAIN = = = = = = = = = =\n");
	fprintf(out, "_start:\n");
	// print main function
	return root;
}
/*
_start:
	add dword [rel vint_x], 10 ; Add
	lea rsi, [rel vstr_text]
	mov rdx, len_text
	call prt ; Print string
	sub dword [rel vint_x], 2 ; Sub
	add dword [rel vint_x], 5 ; Add
	mov eax, [rel vint_x]
	call intToText
	call prt ; Print int
	lea rsi, [rel nl]
	mov rdx, nll
	call prt ; Print line
	mov rax, 60
	mov rdi, 0
	syscall
*/


void endCompiler() {
	if (out && root) {
		fprintf(out, "\t; = = = END = = =\n");
		fprintf(out, "\trax, 60\n");
		fprintf(out, "\tmov rdi, 0\n");
		fprintf(out, "\tsyscall\n");
		fclose(out);
		free(root);
	}
}
