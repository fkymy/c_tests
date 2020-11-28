			global		_ft_strcpy

			section		.text
_ft_strcpy:
			mov			rcx, -1 ; index
			xor			rax, rax

.loop:
			inc			rcx
			mov			bl, [rsi + rcx] ; move a byte of memory content starting at rsi (src) + rcx addr
			mov			[rdi + rcx], bl ; move a byte of memory content to rdi (dst) + rcx addr
			test		bl, bl ; faster cmp bl, 0
			jnz			.loop
			jz			.end

.end:
			mov			rax, rdi
			ret
