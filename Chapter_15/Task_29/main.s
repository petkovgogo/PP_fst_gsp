	.file	"main.cpp"
# GNU C++14 (Ubuntu 9.3.0-17ubuntu1~20.04) version 9.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.3.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE main.cpp
# -mtune=generic -march=x86-64 -fverbose-asm -fasynchronous-unwind-tables
# -fstack-protector-strong -Wformat -Wformat-security
# -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -fexceptions -ffp-int-builtin-inexact
# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
# -finline-atomics -fipa-stack-alignment -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstack-clash-protection
# -fstack-protector-strong -fstdarg-opt -fstrict-volatile-bitfields
# -fsync-libcalls -ftrapping-math -ftree-cselim -ftree-forwprop
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.text._ZN1XC2Ev,"axG",@progbits,_ZN1XC5Ev,comdat
	.align 2
	.weak	_ZN1XC2Ev
	.type	_ZN1XC2Ev, @function
_ZN1XC2Ev:
.LFB1:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# main.cpp:4:     X() { func(); }
	leaq	16+_ZTV1X(%rip), %rdx	#, _1
	movq	-8(%rbp), %rax	# this, tmp83
	movq	%rdx, (%rax)	# _1, this_3(D)->_vptr.X	# vptr initialised here
# main.cpp:4:     X() { func(); }
	movq	-8(%rbp), %rax	# this, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZN1X4funcEv	#
# main.cpp:4:     X() { func(); }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	_ZN1XC2Ev, .-_ZN1XC2Ev
	.weak	_ZN1XC1Ev
	.set	_ZN1XC1Ev,_ZN1XC2Ev
	.section	.text._ZN1X4funcEv,"axG",@progbits,_ZN1X4funcEv,comdat
	.align 2
	.weak	_ZN1X4funcEv
	.type	_ZN1X4funcEv, @function
_ZN1X4funcEv:
.LFB3:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# main.cpp:9:     virtual void func() {}
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3:
	.size	_ZN1X4funcEv, .-_ZN1X4funcEv
	.section	.text._ZN1YC2Ev,"axG",@progbits,_ZN1YC5Ev,comdat
	.align 2
	.weak	_ZN1YC2Ev
	.type	_ZN1YC2Ev, @function
_ZN1YC2Ev:
.LFB5:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# main.cpp:15:     Y() { func(); }
	movq	-8(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZN1XC2Ev	#
	leaq	16+_ZTV1Y(%rip), %rdx	#, _2
	movq	-8(%rbp), %rax	# this, tmp84
	movq	%rdx, (%rax)	# _2, this_4(D)->D.2336._vptr.X		# vptr initialised here
# main.cpp:15:     Y() { func(); }
	movq	-8(%rbp), %rax	# this, tmp85
	movq	%rax, %rdi	# tmp85,
	call	_ZN1Y4funcEv	#
# main.cpp:15:     Y() { func(); }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE5:
	.size	_ZN1YC2Ev, .-_ZN1YC2Ev
	.weak	_ZN1YC1Ev
	.set	_ZN1YC1Ev,_ZN1YC2Ev
	.section	.text._ZN1Y4funcEv,"axG",@progbits,_ZN1Y4funcEv,comdat
	.align 2
	.weak	_ZN1Y4funcEv
	.type	_ZN1Y4funcEv, @function
_ZN1Y4funcEv:
.LFB7:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# main.cpp:17:     void func() {}
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE7:
	.size	_ZN1Y4funcEv, .-_ZN1Y4funcEv
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# main.cpp:21: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp86
	movq	%rax, -8(%rbp)	# tmp86, D.2420
	xorl	%eax, %eax	# tmp86
# main.cpp:22:     Y yObj;
	leaq	-16(%rbp), %rax	#, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZN1YC1Ev	#
# main.cpp:24:     return 0;
	movl	$0, %eax	#, _3
# main.cpp:25: }
	movq	-8(%rbp), %rdx	# D.2420, tmp87
	xorq	%fs:40, %rdx	# MEM[(<address-space-1> long unsigned int *)40B], tmp87
	je	.L7	#,
	call	__stack_chk_fail@PLT	#
.L7:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.weak	_ZTV1Y
	.section	.data.rel.ro.local._ZTV1Y,"awG",@progbits,_ZTV1Y,comdat
	.align 8
	.type	_ZTV1Y, @object
	.size	_ZTV1Y, 24
_ZTV1Y:
	.quad	0
	.quad	_ZTI1Y
	.quad	_ZN1Y4funcEv
	.weak	_ZTV1X
	.section	.data.rel.ro.local._ZTV1X,"awG",@progbits,_ZTV1X,comdat
	.align 8
	.type	_ZTV1X, @object
	.size	_ZTV1X, 24
_ZTV1X:
	.quad	0
	.quad	_ZTI1X
	.quad	_ZN1X4funcEv
	.weak	_ZTI1Y
	.section	.data.rel.ro._ZTI1Y,"awG",@progbits,_ZTI1Y,comdat
	.align 8
	.type	_ZTI1Y, @object
	.size	_ZTI1Y, 24
_ZTI1Y:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
# <anonymous>:
	.quad	_ZTS1Y
# <anonymous>:
	.quad	_ZTI1X
	.weak	_ZTS1Y
	.section	.rodata._ZTS1Y,"aG",@progbits,_ZTS1Y,comdat
	.type	_ZTS1Y, @object
	.size	_ZTS1Y, 3
_ZTS1Y:
	.string	"1Y"
	.weak	_ZTI1X
	.section	.data.rel.ro._ZTI1X,"awG",@progbits,_ZTI1X,comdat
	.align 8
	.type	_ZTI1X, @object
	.size	_ZTI1X, 16
_ZTI1X:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
# <anonymous>:
	.quad	_ZTS1X
	.weak	_ZTS1X
	.section	.rodata._ZTS1X,"aG",@progbits,_ZTS1X,comdat
	.type	_ZTS1X, @object
	.size	_ZTS1X, 3
_ZTS1X:
	.string	"1X"
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
