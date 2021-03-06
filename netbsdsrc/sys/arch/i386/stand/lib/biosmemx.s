/*	$NetBSD: biosmemx.S,v 1.1 1997/08/14 15:22:00 drochner Exp $	*/

/*
 * Copyright (c) 1997
 *	Matthias Drochner.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed for the NetBSD Project
 *	by Matthias Drochner.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <machine/asm.h>

#define	data32	.byte 0x66

	.text

/* int getextmem2(int buffer[2])
   return: 0=OK, -1=error
   buffer[0]: extmem kBytes below 16M (max 15M/1024)
   buffer[1]: extmem above 16M, in 64k units
*/
ENTRY(getextmem2)
	pushl	%ebp
	movl	%esp,%ebp
	pushl	%ebx
	pushl	%ecx
	pushl	%edx
	push	%esi
	push	%edi

	call	_C_LABEL(prot_to_real)

	data32
	movl	$0xe801, %eax
	int	$0x15
	jc	err2

	data32
	movl	$0, %ecx
	jmp ok2
err2:
	data32
	movl	$-1, %ecx
ok2:
	data32
	movl	%eax, %edx

	data32
	call	_C_LABEL(real_to_prot)

	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	%ebx, 4(%eax)

	movl	%ecx, %eax

	pop	%edi
	pop	%esi
	popl	%edx
	popl	%ecx
	popl	%ebx
	popl	%ebp
	ret

/* int getmementry(int iterator, buffer[5])
   return: new iterator, 0=end of list or error
   buffer[0]: start of memory chunk
   buffer[2]: length (bytes)
   buffer[4]: type
*/
ENTRY(getmementry)
	pushl	%ebp
	movl	%esp,%ebp
	pushl	%ebx
	pushl	%ecx
	pushl	%edx
	push	%esi
	push	%edi

	movl	8(%ebp), %ebx
	movl	$20, %ecx
	movl	$0x534d4150, %edx	# "SMAP"
	movl	12(%ebp), %edi

	call	_C_LABEL(prot_to_real)

	data32
	movl	$0xe820, %eax
	int	$0x15

	jnc	ok
	data32
	movl	$0, %ebx

ok:
	data32
	call	_C_LABEL(real_to_prot)

	movl	%ebx, %eax

	pop	%edi
	pop	%esi
	popl	%edx
	popl	%ecx
	popl	%ebx
	popl	%ebp
	ret
