section .text
bits 64
default rel

global x64distance

x64distance:

push rbp
mov rbp, rsp
add rbp, 16

xor rbx, rbx

L1:
	movsd xmm1, [rdx + rbx * 8]
	movsd xmm2, [r8 + rbx * 8]

	subsd xmm2, xmm1
	mulsd xmm2, xmm2

	movsd xmm3, [r9 + rbx * 8]
	mov rsi, [rbp+32]
	movsd xmm4, [rsi + rbx * 8]

	subsd xmm4, xmm3
	mulsd xmm4, xmm4

	addsd xmm2, xmm4

	sqrtsd xmm2, xmm2


	mov rsi, [rbp+40]
	movsd [rsi + rbx * 8], xmm2

	inc rbx
	loop L1
pop rbp
ret