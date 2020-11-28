			global		_ft_write
			extern		___error

			section		.data
SYS_WRITE	equ			0x02000004

			section		.text
_ft_write:
			mov			rax, SYS_WRITE
			syscall
			jc			.err
			jmp			.end

.err:
			push		rax
			call		___error
			pop			rcx
			mov			[rax], rcx ; set errno to write return value
			mov			rax, -1

.end:
			ret
