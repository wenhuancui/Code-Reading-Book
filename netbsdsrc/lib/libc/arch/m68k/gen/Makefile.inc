#	$NetBSD: Makefile.inc,v 1.6.2.1 1997/11/05 02:18:20 mellon Exp $

SRCS+=	_setjmp.S alloca.S fabs.S frexp.c infinity.c isinf.c modf.S \
	setjmp.S sigsetjmp.S
SRCS+=	flt_rounds.S fpgetmask.S fpgetround.S fpgetsticky.S fpsetmask.S \
	fpsetround.S fpsetsticky.S
SRCS+=	adddf3.S addsf3.S ashlsi3.S ashrsi3.S cmpdf2.S cmpsf2.S divdf3.S \
	divsf3.S divsi3.S extendsfdf2.S fixdfsi.S fixunsdfsi.S \
	floatsidf.S lshlsi3.S lshrsi3.S modsi3.S muldf3.S mulsf3.S mulsi3.S \
	negdf2.S negsf2.S subdf3.S subsf3.S truncdfsf2.S udivsi3.S \
	umodsi3.S umulsi3.S

.ifdef(M68040)
SRCS+=	ldexp.c
.elifdef(M68060)
SRCS+=	ldexp.c
.else
SRCS+=	ldexp.S 
.endif
