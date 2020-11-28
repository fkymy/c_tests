; -----------------------------------------------------------------------------
; A 64-bit program that displays its command line arguments, one per line.
;
; On entry, rdi will contain argc and rsi will contain argv.
; -----------------------------------------------------------------------------

			global		_main
			extern		_puts
			section		.text

_main:
			push		rdi ; 1st arg of main
			push		rsi ; 2nd arg of main
			sub			rsp, 8 ; align stack before call
			mov			rdi, [rsi]
			call		_puts
			add			rsp, 8
			pop			rsi
			pop			rdi
			add			rsi, 8 ; point to next arg
			dec			rdi
			jnz			_main
			ret
