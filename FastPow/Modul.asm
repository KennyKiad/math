.code

asm_get_mod proc
;XMM0 - x
;XMM1 - y
	
	xor edx,edx

	mov rax,4000000000000000h
	push rax
	fld qword ptr[rsp]
	mov rax,4008000000000000h
	push rax
	fld qword ptr[rsp]
	pop rax
	pop rax


	fdiv st,st(1)
	fprem
	

	ret
asm_get_mod endp

end