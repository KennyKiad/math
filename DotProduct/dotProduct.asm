.code

dotPdbl proc
;double dotPdbl(double* vec1, double* vec2, unsigned int dim)
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
dotPdbl endp

dotPfl proc
;float dotPfl(float* vec1, float* vec2, unsigned int dim);
;RCX = float* vec1
;RDX = float* vec2
;R8d = unsigned int dim
	
	push rbx

	xor ebx,ebx
	xorpd xmm0,xmm0

	cmp r8d,2
	jae @@do

@@single:
	movq xmm1,qword ptr[rcx+rbx*4]
	movq xmm2,qword ptr[rdx+rbx*4]
	mulps xmm1,xmm2
	haddps xmm1,xmm1
	addss xmm0,xmm1
	
	jmp @@end

@@do:
	movups xmm1,[rcx+rbx*4]
	movups xmm2,[rdx+rbx*4]
	mulps xmm1,xmm2
	haddps xmm1,xmm1
	haddps xmm1,xmm1
	addss xmm0,xmm1

	add ebx,4
	mov rax,r8
	sub rax,rbx
	cmp rax,2
	je @@single

	cmp ebx,r8d
	jb @@do

@@end:

	pop rbx

	ret
dotPfl endp

end