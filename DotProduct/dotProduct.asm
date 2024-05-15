.code

dotP proc
;RCX = double* vec1
;RDX = double* vec2
;R8d = unsigned int dim
	
	push rbx

	xor ebx,ebx
	xorpd xmm0,xmm0

	cmp r8d,2
	jae @@do

@@single:
	movsd xmm1,qword ptr[rcx+rbx*8]
	mulsd xmm1,qword ptr[rdx+rbx*8]
	addpd xmm0,xmm1
	jmp @@end

@@do:
	movupd xmm1,[rcx+rbx*8]
	movupd xmm2,[rdx+rbx*8]
	mulpd xmm1,xmm2
	haddpd xmm1,xmm1
	addpd xmm0,xmm1

	add ebx,2
	mov rax,r8
	sub rax,rbx
	cmp rax,1
	je @@single

	cmp ebx,r8d
	jb @@do

@@end:

	pop rbx

	ret
dotP endp

end