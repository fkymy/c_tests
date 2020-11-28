; -----------------------------------------------------------------------------
; A 64-bit Mac OSX application that writes the first 90 Fibonacci numbers. To
; assemble and run:
;
;     /usr/local/bin/nasm -f macho64 fib.asm && gcc -arch x86_64 -o fib fib.o && ./fib
; -----------------------------------------------------------------------------

			global		_main
			extern		_printf

			section		.text
_main		push		rbx		; we are required to reserve rbx because we use it
			mov			ecx, 90
			xor			rax, rax ; current number
			xor			rbx, rbx ; next number
			inc			rbx ; originally 1

print:
	; We need to call printf, but we are using rax, rbx, and rcx. printf may
	; destroy rax and rcx, so we will save these before the call and restore them afterwards.
			push		rax
			push		rcx
			lea			rdi, [rel format] ; 1st param
			mov			rsi, rax ; 2nd param
			xor			rax, rax ; zero rax before call to printf. rax is used to indicate num of vector
								 ; registers used with varg functions
			call		_printf
			pop			rcx
			pop			rax
			mov			rdx, rax ; prev
			mov			rax, rbx ; next number is now current number
			add			rbx, rdx ; next number is current number + prev
			dec			ecx
			jnz			print

			pop			rbx ; restore rbx before returning
			ret

			section		.data
format:		db			"%20ld", 10, 0
