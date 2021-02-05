	.file	"main.cpp"
# GNU C++14 (Ubuntu 9.3.0-17ubuntu1~20.04) version 9.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.3.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE main.cpp
# -mtune=generic -march=x86-64 -O0 -fverbose-asm
# -fasynchronous-unwind-tables -fstack-protector-strong -Wformat
# -Wformat-security -fstack-clash-protection -fcf-protection
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
.LC2:
	.string	"(num1 + num2) = "
.LC3:
	.string	"(num1 - num2) = "
.LC4:
	.string	"(num1 * num2) = "
.LC5:
	.string	"(num1 / num2) = "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1522:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# main.cpp:8:     double num1 = 6.63;
	movsd	.LC0(%rip), %xmm0	#, tmp96
	movsd	%xmm0, -16(%rbp)	# tmp96, num1
# main.cpp:9:     double num2 = 9.81;
	movsd	.LC1(%rip), %xmm0	#, tmp97
	movsd	%xmm0, -8(%rbp)	# tmp97, num2
# main.cpp:11:     EVALUATE((num1 + num2))
	leaq	.LC2(%rip), %rsi	#,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movsd	-16(%rbp), %xmm0	# num1, tmp98
	addsd	-8(%rbp), %xmm0	# num2, _2						# adds the two numbers
	movq	%rax, %rdi	# _1,
	call	_ZNSolsEd@PLT	#
	movq	%rax, %rdx	#, _3
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp99
	movq	%rax, %rsi	# tmp99,
	movq	%rdx, %rdi	# _3,
	call	_ZNSolsEPFRSoS_E@PLT	#
# main.cpp:12:     EVALUATE((num1 - num2))
	leaq	.LC3(%rip), %rsi	#,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movsd	-16(%rbp), %xmm0	# num1, tmp100
	subsd	-8(%rbp), %xmm0	# num2, _5						# substracts the two numbers
	movq	%rax, %rdi	# _4,
	call	_ZNSolsEd@PLT	#
	movq	%rax, %rdx	#, _6
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp101
	movq	%rax, %rsi	# tmp101,
	movq	%rdx, %rdi	# _6,
	call	_ZNSolsEPFRSoS_E@PLT	#
# main.cpp:13:     EVALUATE((num1 * num2))
	leaq	.LC4(%rip), %rsi	#,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movsd	-16(%rbp), %xmm0	# num1, tmp102
	mulsd	-8(%rbp), %xmm0	# num2, _8						# multiplies the two numbers
	movq	%rax, %rdi	# _7,
	call	_ZNSolsEd@PLT	#
	movq	%rax, %rdx	#, _9
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp103
	movq	%rax, %rsi	# tmp103,
	movq	%rdx, %rdi	# _9,
	call	_ZNSolsEPFRSoS_E@PLT	#
# main.cpp:14:     EVALUATE((num1 / num2))
	leaq	.LC5(%rip), %rsi	#,
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movsd	-16(%rbp), %xmm0	# num1, tmp104
	divsd	-8(%rbp), %xmm0	# num2, _11						# divides the two numbers
	movq	%rax, %rdi	# _10,
	call	_ZNSolsEd@PLT	#
	movq	%rax, %rdx	#, _12
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax	#, tmp105
	movq	%rax, %rsi	# tmp105,
	movq	%rdx, %rdi	# _12,
	call	_ZNSolsEPFRSoS_E@PLT	#
# main.cpp:16:     return 0;
	movl	$0, %eax	#, _36
# main.cpp:17: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1522:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2012:
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
# main.cpp:17: }
	cmpl	$1, -4(%rbp)	#, __initialize_p
	jne	.L5	#,
# main.cpp:17: }
	cmpl	$65535, -8(%rbp)	#, __priority
	jne	.L5	#,
# /usr/include/c++/9/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rdi	#,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	leaq	__dso_handle(%rip), %rdx	#,
	leaq	_ZStL8__ioinit(%rip), %rsi	#,
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax	#, tmp82
	movq	%rax, %rdi	# tmp82,
	call	__cxa_atexit@PLT	#
.L5:
# main.cpp:17: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2012:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2013:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# main.cpp:17: }
	movl	$65535, %esi	#,
	movl	$1, %edi	#,
	call	_Z41__static_initialization_and_destruction_0ii	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2013:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
.LC0:
	.long	3092376453
	.long	1075479838
	.align 8
.LC1:
	.long	1374389535
	.long	1076076216
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
