	.file	"funtemplate.cpp"
	.text
	.def	__ZL6printfPKcz;	.scl	3;	.type	32;	.endef
__ZL6printfPKcz:
LFB310:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	leal	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_vprintf
	movl	%eax, %ebx
	movl	%ebx, %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE310:
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
LC0:
	.ascii "%d %d \12\0"
LC1:
	.ascii "%c %c \12\0"
	.text
	.globl	__Z6main01v
	.def	__Z6main01v;	.scl	2;	.type	32;	.endef
__Z6main01v:
LFB1078:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$10, -12(%ebp)
	movl	$20, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z6myswapIiEvRT_S1_
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	__ZL6printfPKcz
	movb	$97, -17(%ebp)
	movb	$98, -18(%ebp)
	leal	-18(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-17(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z6myswapIcEvRT_S1_
	movzbl	-18(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-17(%ebp), %eax
	movsbl	%al, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	__ZL6printfPKcz
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z6myswapIiEvRT_S1_
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1078:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC2:
	.ascii "\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1079:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$96, %esp
	call	___main
	movl	$33, 48(%esp)
	movl	$12, 52(%esp)
	movl	$8, 56(%esp)
	movl	$1, 60(%esp)
	movl	$0, 64(%esp)
	movl	$55, 68(%esp)
	movl	$88, 72(%esp)
	movl	$31, 76(%esp)
	movl	$8, 80(%esp)
	movl	$6, 84(%esp)
	movl	$10, %eax
	movl	%eax, 92(%esp)
	movl	92(%esp), %eax
	movl	%eax, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z6mySortIiiEvPT_T0_
	movl	92(%esp), %eax
	movl	%eax, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z7myprintIiiEvPT_T0_
	movl	$LC2, (%esp)
	call	__ZL6printfPKcz
	movl	$1634493547, 23(%esp)
	movl	$2054185316, 27(%esp)
	movl	$1684107375, 31(%esp)
	movl	$1785033057, 35(%esp)
	movl	$1785032817, 39(%esp)
	movl	$1633968497, 43(%esp)
	movb	$0, 47(%esp)
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, 88(%esp)
	movl	88(%esp), %eax
	movl	%eax, 4(%esp)
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	__Z6mySortIciEvPT_T0_
	movl	88(%esp), %eax
	movl	%eax, 4(%esp)
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	__Z7myprintIciEvPT_T0_
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1079:
	.section	.text$_Z6myswapIiEvRT_S1_,"x"
	.linkonce discard
	.globl	__Z6myswapIiEvRT_S1_
	.def	__Z6myswapIiEvRT_S1_;	.scl	2;	.type	32;	.endef
__Z6myswapIiEvRT_S1_:
LFB1080:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1080:
	.section	.text$_Z6myswapIcEvRT_S1_,"x"
	.linkonce discard
	.globl	__Z6myswapIcEvRT_S1_
	.def	__Z6myswapIcEvRT_S1_;	.scl	2;	.type	32;	.endef
__Z6myswapIcEvRT_S1_:
LFB1081:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, -1(%ebp)
	movl	12(%ebp), %eax
	movzbl	(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	12(%ebp), %eax
	movzbl	-1(%ebp), %edx
	movb	%dl, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1081:
	.section	.text$_Z6mySortIiiEvPT_T0_,"x"
	.linkonce discard
	.globl	__Z6mySortIiiEvPT_T0_
	.def	__Z6mySortIiiEvPT_T0_;	.scl	2;	.type	32;	.endef
__Z6mySortIiiEvPT_T0_:
LFB1082:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -4(%ebp)
L14:
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	L15
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -8(%ebp)
L13:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	L11
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	L12
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
L12:
	addl	$1, -8(%ebp)
	jmp	L13
L11:
	addl	$1, -4(%ebp)
	jmp	L14
L15:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1082:
	.section .rdata,"dr"
LC3:
	.ascii " \0"
	.section	.text$_Z7myprintIiiEvPT_T0_,"x"
	.linkonce discard
	.globl	__Z7myprintIiiEvPT_T0_
	.def	__Z7myprintIiiEvPT_T0_;	.scl	2;	.type	32;	.endef
__Z7myprintIiiEvPT_T0_:
LFB1083:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	$0, -12(%ebp)
L18:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	L19
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$1, -12(%ebp)
	jmp	L18
L19:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1083:
	.section	.text$_Z6mySortIciEvPT_T0_,"x"
	.linkonce discard
	.globl	__Z6mySortIciEvPT_T0_
	.def	__Z6mySortIciEvPT_T0_;	.scl	2;	.type	32;	.endef
__Z6mySortIciEvPT_T0_:
LFB1084:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -4(%ebp)
L25:
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	L26
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -8(%ebp)
L24:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	L22
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %edx
	movl	-8(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	jle	L23
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-12(%ebp), %edx
	movb	%dl, (%eax)
L23:
	addl	$1, -8(%ebp)
	jmp	L24
L22:
	addl	$1, -4(%ebp)
	jmp	L25
L26:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1084:
	.section	.text$_Z7myprintIciEvPT_T0_,"x"
	.linkonce discard
	.globl	__Z7myprintIciEvPT_T0_
	.def	__Z7myprintIciEvPT_T0_;	.scl	2;	.type	32;	.endef
__Z7myprintIciEvPT_T0_:
LFB1085:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	$0, -12(%ebp)
L29:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	L30
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$1, -12(%ebp)
	jmp	L29
L30:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1085:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1091:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1091:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1090:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L34
	cmpl	$65535, 12(%ebp)
	jne	L34
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L34:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1090:
	.def	__GLOBAL__sub_I__Z6main01v;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z6main01v:
LFB1092:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1092:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z6main01v
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 5.3.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
