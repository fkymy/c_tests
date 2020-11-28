; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit macOS only.
; To assemble and run:
;
;     nasm -fmacho64 hello.asm && ld hello.o -lSystem && ./a.out
; ----------------------------------------------------------------------------------------


; Labels	Instructions	Operands

; Directives
			global		_main

; Sections
			section		.text
_main:		mov			rax, SYS_WRITE
			mov			rdi, STDOUT
			mov			rsi, message
			mov			rdx, len
			syscall
			mov			rax, SYS_EXIT
			xor			rdi, rdi
			syscall

			section		.data
message:	db			"Hello, World", 10
len:		equ			$ - message

SYS_EXIT	equ			0x02000001
SYS_WRITE	equ			0x02000004
STDIN		equ			0
STDOUT		equ			1
