			global		_ft_strdup
			extern		_ft_strlen
			extern		_malloc
			extern		_ft_strcpy

			section		.text
_ft_strdup:
			test		rdi, rdi
			jz			.err

			call		_ft_strlen
			push		rdi
			add			rax, 1
			mov			rdi, rax
			call		_malloc
			test		rax, rax
			jz			.err

			pop			rdi
			mov			rsi, rdi
			mov			rdi, rax
			call		_ft_strcpy
			ret

.err:
			mov			rax, 0
			ret
