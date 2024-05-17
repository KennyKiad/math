.code

asm_mod proc
;double asm_mod(double x, double y);
;XMM0 - x
;XMM1 - y
	
	add rsp,-8
	
	movq qword ptr[rsp],xmm1
	fld qword ptr[rsp]

	movq qword ptr[rsp],xmm0
	fld qword ptr[rsp]

	fprem
	
	fstp qword ptr[rsp]
	fstp st
	movq xmm0, qword ptr[rsp]

	add rsp,8

	ret
asm_mod endp

end