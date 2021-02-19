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
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
.LC0:
	.string	"virtual void Derived::func()"
	.section	.text._ZN7Derived4funcEv,"axG",@progbits,_ZN7Derived4funcEv,comdat
	.align 2
	.weak	_ZN7Derived4funcEv
	.type	_ZN7Derived4funcEv, @function
_ZN7Derived4funcEv:
.LFB1523:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	# ,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	# ,
	movq	%rdi, -8(%rbp)	# this, this
# main.cpp:12:     void func() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	leaq	.LC0(%rip), %rsi	# ,
	leaq	_ZSt4cout(%rip), %rdi	# ,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	# , _1
# main.cpp:12:     void func() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp83
	movq	%rax, %rsi	# tmp83,
	movq	%rdx, %rdi	# _1,
	call	_ZNSolsEPFRSoS_E@PLT	#
# main.cpp:12:     void func() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1523:
	.size	_ZN7Derived4funcEv, .-_ZN7Derived4funcEv
	.text
	.globl	main
	.type	main, @function
main:
.LFB1524:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	# ,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	# ,
# main.cpp:16: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp91
	movq	%rax, -8(%rbp)	# tmp91, D.40060
	xorl	%eax, %eax	# tmp91
# main.cpp:17:     Derived dObj;
	leaq	16+_ZTV7Derived(%rip), %rax	#, _1
	movq	%rax, -24(%rbp)	# _1, dObj.D.36337._vptr.Base
# main.cpp:18:     Base &baseRef = dObj;
	leaq	-24(%rbp), %rax	# , tmp87
	movq	%rax, -16(%rbp)	# tmp87, baseRef
# main.cpp:20:     baseRef.func();
	movq	-16(%rbp), %rax	# baseRef, tmp88
	movq	(%rax), %rax	# baseRef_6->_vptr.Base, _2
	movq	(%rax), %rdx	# *_2, _3
# main.cpp:20:     baseRef.func();
	movq	-16(%rbp), %rax	# baseRef, tmp89
	movq	%rax, %rdi	# tmp89,
	call	*%rdx	# _3
# main.cpp:22:     return 0;
	movl	$0, %eax	#, _8
# main.cpp:23: }
	movq	-8(%rbp), %rcx	# D.40060, tmp92
	xorq	%fs:40, %rcx	# MEM[(<address-space-1> long unsigned int *)40B], tmp92
	je	.L4	#,
	call	__stack_chk_fail@PLT	#
.L4:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1524:
	.size	main, .-main
	.weak	_ZTV7Derived
	.section	.data.rel.ro.local._ZTV7Derived,"awG",@progbits,_ZTV7Derived,comdat
	.align 8
	.type	_ZTV7Derived, @object
	.size	_ZTV7Derived, 24
_ZTV7Derived:
	.quad	0
	.quad	_ZTI7Derived
	.quad	_ZN7Derived4funcEv
	.weak	_ZTI7Derived
	.section	.data.rel.ro._ZTI7Derived,"awG",@progbits,_ZTI7Derived,comdat
	.align 8
	.type	_ZTI7Derived, @object
	.size	_ZTI7Derived, 24
_ZTI7Derived:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
# <anonymous>:
	.quad	_ZTS7Derived
# <anonymous>:
	.quad	_ZTI4Base
	.weak	_ZTS7Derived
	.section	.rodata._ZTS7Derived,"aG",@progbits,_ZTS7Derived,comdat
	.align 8
	.type	_ZTS7Derived, @object
	.size	_ZTS7Derived, 9
_ZTS7Derived:
	.string	"7Derived"
	.weak	_ZTI4Base
	.section	.data.rel.ro._ZTI4Base,"awG",@progbits,_ZTI4Base,comdat
	.align 8
	.type	_ZTI4Base, @object
	.size	_ZTI4Base, 16
_ZTI4Base:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
# <anonymous>:
	.quad	_ZTS4Base
	.weak	_ZTS4Base
	.section	.rodata._ZTS4Base,"aG",@progbits,_ZTS4Base,comdat
	.type	_ZTS4Base, @object
	.size	_ZTS4Base, 6
_ZTS4Base:
	.string	"4Base"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2019:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	# ,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	# ,
	movl	%edi, -4(%rbp)	# __initialize_p, __initialize_p
	movl	%esi, -8(%rbp)	# __priority, __priority
# main.cpp:23: }
	cmpl	$1, -4(%rbp)	# , __initialize_p
	jne	.L7	#,
# main.cpp:23: }
	cmpl	$65535, -8(%rbp)	# , __priority
	jne	.L7	#,
# /usr/include/c++/9/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rdi	# ,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	leaq	__dso_handle(%rip), %rdx	# ,
	leaq	_ZStL8__ioinit(%rip), %rsi	# ,
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax	# , tmp82
	movq	%rax, %rdi	# tmp82,
	call	__cxa_atexit@PLT	#
.L7:
# main.cpp:23: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2019:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2020:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	# ,
	.cfi_def_cfa_register 6
# main.cpp:23: }
	movl	$65535, %esi	# ,
	movl	$1, %edi	# ,
	call	_Z41__static_initialization_and_destruction_0ii	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2020:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
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
