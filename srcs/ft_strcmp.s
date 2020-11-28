			global		_ft_strcmp

			section		.text
_ft_strcmp:
			push		rbx
			xor			rcx, rcx ; index
			xor			rbx, rbx ; clear for bl
			xor			rax, rax ; clear for al and return value

.loop:
			mov			al, byte [rdi + rcx]
			mov			bl, byte [rsi + rcx]
			cmp			al, bl
			jne			.diff
			je			.same

.same:
			test		al, al ; faster cmp al, 0
			jz			.end
			inc			rcx
			jmp			.loop

.diff:
			sub			rax, rbx ; lowest bytes are al, bl
			jmp			.end

.end:
			pop			rbx
			ret
