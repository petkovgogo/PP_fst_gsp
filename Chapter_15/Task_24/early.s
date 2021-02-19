	.file	"early.cpp"
# GNU C++14 (Ubuntu 9.3.0-17ubuntu1~20.04) version 9.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.3.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE early.cpp
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
	.string	""
	.section	.text._ZNK3Pet5speakEv,"axG",@progbits,_ZNK3Pet5speakEv,comdat
	.align 2
	.weak	_ZNK3Pet5speakEv
	.type	_ZNK3Pet5speakEv, @function
_ZNK3Pet5speakEv:
.LFB1522:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# early.cpp:6:     virtual const char *speak() const { return ""; }
	leaq	.LC0(%rip), %rax	#, _1
# early.cpp:6:     virtual const char *speak() const { return ""; }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1522:
	.size	_ZNK3Pet5speakEv, .-_ZNK3Pet5speakEv
	.section	.rodata
.LC1:
	.string	"Bark!"
	.section	.text._ZNK3Dog5speakEv,"axG",@progbits,_ZNK3Dog5speakEv,comdat
	.align 2
	.weak	_ZNK3Dog5speakEv
	.type	_ZNK3Dog5speakEv, @function
_ZNK3Dog5speakEv:
.LFB1523:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# early.cpp:12:     const char *speak() const { return "Bark!"; }
	leaq	.LC1(%rip), %rax	#, _1
# early.cpp:12:     const char *speak() const { return "Bark!"; }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1523:
	.size	_ZNK3Dog5speakEv, .-_ZNK3Dog5speakEv
	.section	.rodata
.LC2:
	.string	"p1->speak() = "
.LC3:
	.string	"p2.speak() = "
.LC4:
	.string	"p3.speak() = "
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
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$56, %rsp	#,
	.cfi_offset 3, -24
# early.cpp:16: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp110
	movq	%rax, -24(%rbp)	# tmp110, D.40082
	xorl	%eax, %eax	# tmp110
# early.cpp:17:     Dog ralph;
	leaq	16+_ZTV3Dog(%rip), %rax	#, _1
	movq	%rax, -56(%rbp)	# _1, ralph.D.36296._vptr.Pet
# early.cpp:18:     Pet *p1 = &ralph;
	leaq	-56(%rbp), %rax	#, tmp99
	movq	%rax, -40(%rbp)	# tmp99, p1
# early.cpp:19:     Pet &p2 = ralph;
	leaq	-56(%rbp), %rax	#, tmp100
	movq	%rax, -32(%rbp)	# tmp100, p2
# early.cpp:20:     Pet p3;
	leaq	16+_ZTV3Pet(%rip), %rax	#, _2
	movq	%rax, -48(%rbp)	# _2, p3._vptr.Pet
# early.cpp:23:     std::cout << "p1->speak() = " << p1->speak() << std::endl;
	leaq	.LC2(%rip), %rsi	#,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rbx	#, _3
	movq	-40(%rbp), %rax	# p1, tmp101
	movq	(%rax), %rax	# p1_19->_vptr.Pet, _4                           The vptr is used => late binding
	movq	(%rax), %rdx	# *_4, _5
	movq	-40(%rbp), %rax	# p1, tmp102
	movq	%rax, %rdi	# tmp102,
	call	*%rdx	# _5
	movq	%rax, %rsi	# _6,
	movq	%rbx, %rdi	# _3,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	#, _7
# early.cpp:23:     std::cout << "p1->speak() = " << p1->speak() << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp103
	movq	%rax, %rsi	# tmp103,
	movq	%rdx, %rdi	# _7,
	call	_ZNSolsEPFRSoS_E@PLT	#
# early.cpp:24:     std::cout << "p2.speak() = " << p2.speak() << std::endl;
	leaq	.LC3(%rip), %rsi	#,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rbx	#, _8
	movq	-32(%rbp), %rax	# p2, tmp104
	movq	(%rax), %rax	# p2_20->_vptr.Pet, _9                           The vptr is used => late binding
	movq	(%rax), %rdx	# *_9, _10
	movq	-32(%rbp), %rax	# p2, tmp105
	movq	%rax, %rdi	# tmp105,
	call	*%rdx	# _10
	movq	%rax, %rsi	# _11,
	movq	%rbx, %rdi	# _8,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	#, _12
# early.cpp:24:     std::cout << "p2.speak() = " << p2.speak() << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp106
	movq	%rax, %rsi	# tmp106,
	movq	%rdx, %rdi	# _12,
	call	_ZNSolsEPFRSoS_E@PLT	#
# early.cpp:27:     std::cout << "p3.speak() = " << p3.speak() << std::endl;
	leaq	.LC4(%rip), %rsi	#,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rbx	#, _13
	leaq	-48(%rbp), %rax	#, tmp107
	movq	%rax, %rdi	# tmp107,
	call	_ZNK3Pet5speakEv	#
	movq	%rax, %rsi	# _14,
	movq	%rbx, %rdi	# _13,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	#, _15
# early.cpp:27:     std::cout << "p3.speak() = " << p3.speak() << std::endl; 		The vptr is NOT used => early binding
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp108
	movq	%rax, %rsi	# tmp108,
	movq	%rdx, %rdi	# _15,
	call	_ZNSolsEPFRSoS_E@PLT	#
# early.cpp:29:     return 0;
	movl	$0, %eax	#, _42
# early.cpp:30: }
	movq	-24(%rbp), %rcx	# D.40082, tmp111
	xorq	%fs:40, %rcx	# MEM[(<address-space-1> long unsigned int *)40B], tmp111
	je	.L7	#,
	call	__stack_chk_fail@PLT	#
.L7:
	addq	$56, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1524:
	.size	main, .-main
	.weak	_ZTV3Dog
	.section	.data.rel.ro.local._ZTV3Dog,"awG",@progbits,_ZTV3Dog,comdat
	.align 8
	.type	_ZTV3Dog, @object
	.size	_ZTV3Dog, 24
_ZTV3Dog:
	.quad	0
	.quad	_ZTI3Dog
	.quad	_ZNK3Dog5speakEv
	.weak	_ZTV3Pet
	.section	.data.rel.ro.local._ZTV3Pet,"awG",@progbits,_ZTV3Pet,comdat
	.align 8
	.type	_ZTV3Pet, @object
	.size	_ZTV3Pet, 24
_ZTV3Pet:
	.quad	0
	.quad	_ZTI3Pet
	.quad	_ZNK3Pet5speakEv
	.weak	_ZTI3Dog
	.section	.data.rel.ro._ZTI3Dog,"awG",@progbits,_ZTI3Dog,comdat
	.align 8
	.type	_ZTI3Dog, @object
	.size	_ZTI3Dog, 24
_ZTI3Dog:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
# <anonymous>:
	.quad	_ZTS3Dog
# <anonymous>:
	.quad	_ZTI3Pet
	.weak	_ZTS3Dog
	.section	.rodata._ZTS3Dog,"aG",@progbits,_ZTS3Dog,comdat
	.type	_ZTS3Dog, @object
	.size	_ZTS3Dog, 5
_ZTS3Dog:
	.string	"3Dog"
	.weak	_ZTI3Pet
	.section	.data.rel.ro._ZTI3Pet,"awG",@progbits,_ZTI3Pet,comdat
	.align 8
	.type	_ZTI3Pet, @object
	.size	_ZTI3Pet, 16
_ZTI3Pet:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
# <anonymous>:
	.quad	_ZTS3Pet
	.weak	_ZTS3Pet
	.section	.rodata._ZTS3Pet,"aG",@progbits,_ZTS3Pet,comdat
	.type	_ZTS3Pet, @object
	.size	_ZTS3Pet, 5
_ZTS3Pet:
	.string	"3Pet"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2019:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# __initialize_p, __initialize_p
	movl	%esi, -8(%rbp)	# __priority, __priority
# early.cpp:30: }
	cmpl	$1, -4(%rbp)	#, __initialize_p
	jne	.L10	#,
# early.cpp:30: }
	cmpl	$65535, -8(%rbp)	#, __priority
	jne	.L10	#,
# /usr/include/c++/9/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rdi	#,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	leaq	__dso_handle(%rip), %rdx	#,
	leaq	_ZStL8__ioinit(%rip), %rsi	#,
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax	#, tmp82
	movq	%rax, %rdi	# tmp82,
	call	__cxa_atexit@PLT	#
.L10:
# early.cpp:30: }
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
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# early.cpp:30: }
	movl	$65535, %esi	#,
	movl	$1, %edi	#,
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
