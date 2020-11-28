section .data
codes: db '0123456789ABCDEF'

section .text
global _start
_start:
	; number 1122... in hex format
	mov rax, 0x1122334455667788
	mov rdi, 1 ; stdout
	mov rcx, 64
	; each 4 bits should be output as one hex digit
	; use shift and bitwise AND to isolate them
	; the result is the offset in 'codes' array
.iterate:
	push rax
	sub rcx, 4
	; cl is a register, smallest part of rcx
	; rax -- eax -- ax -- ah + al
	; rcx -- ecx -- cx -- ch + cl
	sar rax, cl ; shift to 60, 56, 52, ... 4, 0
	and rax, 0xf ; clear all bits but the lowest four
	; by shifting rax value and logical ANDing it with mask 0xF,
	; we transform the whole number to its hex digits, which is used as index
	; to add to addrress of label codes

	; lea rsi, [codes + rax]
	mov rsi, codes
	add rsi, rax
	mov rax, 0x02000004
	mov rdx, 1

	push rcx ; syscall leaves rcx and r11 changed
	syscall
	pop rcx

	pop rax
	; test can be used for fastest 'is it a zero?' check
	; see docs for 'test' command
	test rcx, rcx
	jnz .iterate

	mov rax, 0x02000001
	xor rdi, rdi
	syscall
