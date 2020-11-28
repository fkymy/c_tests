; ----------------------------------------------------------------------------------------
; This is an macOS console program that writes "Hola, mundo" on one line and then exits.
; It uses puts from the C library.  To assemble and run:
;
;     nasm -fmacho64 puts.asm && ld puts.o -lSystem && ./a.out
; ----------------------------------------------------------------------------------------

			global		_main
			extern		_puts
			default		rel

			section		.text
_main:		sub			rsp, 8 ; Pad stack frame as required for 64-bit macos (call adds 8 bytes)
			lea			rdi, [message] ;First argument is address of message
			call		_puts
			add			rsp, 8 ; get old stack pointer back
			ret

			section		.data
message:	db			"Hello, asm", 0 ; C strings need to be nul-terminated
