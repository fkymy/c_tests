			global		_parse_int

; returns rax: number, rdx: len
			section		.text
_parse_int:
			mov			al, byte [rdi]
			cmp			al, '-'
			je			.signed
			jmp			_parse_uint
.signed:
			inc			rdi
			call		parse_uint
			neg			rax
			test		rdx, rdx
			jz			.err
			inc			rdx
			ret

.err:
			xor			rax, rax
			ret

_parse_uint:
			mov			r8, 10
			xor			rax, rax
			xor			rcx, rcx
.loop:
			movzx		r9, byte [rdi + rcx]
			cmp			r9b, '0'
			jb			.end
			cmp			r9b, '9'
			ja			.end
			xor			rdx, rdx
			mul			r8
			and			r9b, 0x0f
			add			rax, r9
			inc			rcx
			jmp			.loop
.end:
			mov			rdx, rcx
			ret
