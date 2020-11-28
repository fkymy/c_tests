			global		_ft_read
			extern		___error

			section		.data
SYS_READ	equ			0x02000003

			section		.text
_ft_read:
			mov			rax, SYS_READ
			syscall
			jc			.err
			jmp			.end

.err:
			push		rax
			call		___error
			pop			rcx
			mov			[rax], rcx
			mov			rax, -1

.end:
			ret
