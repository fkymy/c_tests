; -----------------------------------------------------------------------------
; A 64-bit command line application to compute x^y.
;
; Syntax: power x y
; x and y are (32-bit) integers
; -----------------------------------------------------------------------------

			global		_main
			extern		_printf
			extern		_puts
			extern		_atoi

			section		.text
_main:
			push		r12 ; save callee-save registers
			push		r13
			push		r14 ; by pushing 3 registers our stack is already aligned for calls

			cmp			rdi, 3
			jne			err_arg

			mov			r12, rsi ;argv
			; we will use ecx to count down from the exponent to zero, esi to hold the
			; value of the base, and eax to hold the running product.
			mov			rdi, [r12+16] ;argv[2]
			call		_atoi ; y in eax
			cmp			eax, 0 ; disallow negative exponents
			jl			err_neg
			mov			r13d, eax ; y in r13d
			mov			rdi, [r12+8] ; argv[1]
			call		_atoi ; x in eax
			mov			r14d, eax;
			mov			eax, 1 ; start with answer = 1
check:
			test		r13d, r13d ; counting y down to 0
			jz			gotit
			imul		eax, r14d ; multiply in another x
			dec			r13d
			jmp			check
gotit:
			mov			rdi, answer
			movsxd		rsi, eax
			xor			rax, rax
			call		_printf
			jmp			done

err_arg:
			mov			edi, badArgumentCount
			call		_puts
			jmp			done
err_neg:
			mov			edi, negativeExponent
			call		_puts

done:
			pop			r14
			pop			r13
			pop			r12
			ret

			section		.data
answer:		db			"%d", 10, 0
badArgumentCount: db	"Requires exactly two arguments", 10, 0
negativeExponent: db	"The exponent may not be negative", 10, 0
