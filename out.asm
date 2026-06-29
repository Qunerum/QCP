default rel
; db - 255
; dw - 65 535
; dd - 4 294 967 295
; dq - 18 446 744 073 709 551 615
; = = = = = = = = = = VARIABLES = = = = = = = = = =
section .data
	nl db 10 ; \n
	nll equ $ - nl ; \n len
	main_int_x dd 0 ; <func-name>_<var-type>_<var-name>
	public_int_y dd 24 ; public_<var-type>_<var-name>
	test_str db "Hello, World!", 10, "x is: "
	test_str_len equ $ - test_str

	test_string_bufor_len dd 0

section .bss
	bufor resb 12
	test_string_bufor resb 4096

; = = = = = = = = = = INT TO TEXT = = = = = = = = = =
section .text
	global _start
intToText:
	mov rcx, 0
	mov ebx, 10
.ittLoop:
	mov edx, 0
	div ebx
	add edx, 48
	push rdx
	inc rcx
	cmp eax, 0
	jne .ittLoop
	lea rdi, [rel bufor]
	mov rdx, rcx
	lea rsi, [rel bufor]
.ittLoopWrite:
	pop rax
	mov [rdi], al
	inc rdi
	loop .ittLoopWrite
	inc rdx
	ret
; = = = = = = = = = = PRINT = = = = = = = = = =
prt:
	mov rax, 1
	mov rdi, 1
	syscall
	ret
; = = = = = = = = = = MAIN = = = = = = = = = =
_start:
	; User Code
	lea rsi, [rel test_str]
	mov rdx, test_str_len
	call prt ; Print line
	lea rsi, [rel nl]
	mov rdx, nll
	call prt ; Print line
	; = = = END = = =
	mov rax, 60
	mov rdi, 0
	syscall
