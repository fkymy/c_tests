; ----------------------------------------------------------------------------------------
; This is an OSX console program that writes a little triangle of asterisks to standard
; output. Runs on macOS only.
;
;     nasm -fmacho64 triangle.asm && ld triangle.o -lSystem && ./a.out
; ----------------------------------------------------------------------------------------

			global		_main

			section		.text
_main:
			mov			rdx, output
			mov			r8, 1
			mov			r9, 0
line:
			mov			byte [rdx], '*'
			inc			rdx
			inc			r9
			cmp			r9, r8
			jne			line
lineDone:
			mov			byte [rdx], 10
			inc			rdx
			inc			r8
			mov			r9, 0
			cmp			r8, maxlines
			jng			line
done:
			mov			rax, 0x02000004
			mov			rdi, 1
			mov			rsi, output
			mov			rdx, dataSize
			syscall
			mov			rax, 0x02000001
			xor			rdi, rdi
			syscall

			section		.bss ; for writable data
maxlines	equ			8
dataSize	equ			44
output:		resb		dataSize
