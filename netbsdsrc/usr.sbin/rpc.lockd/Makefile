#	$NetBSD: Makefile,v 1.5.2.1 1997/11/08 15:12:30 lukem Exp $

PROG=	rpc.lockd
SRCS=	nlm_prot_svc.c lockd.c lock_proc.c
MAN=	rpc.lockd.8
MLINKS=	rpc.lockd.8 lockd.8

CPPFLAGS+= -I.

DPADD=	${LIBRPCSVC}
LDADD=	-lrpcsvc

CLEANFILES= nlm_prot_svc.c nlm_prot.x nlm_prot.h test

nlm_prot_svc.c: ${DESTDIR}/usr/include/rpcsvc/nlm_prot.x
	rm -f nlm_prot.x
	ln -s ${DESTDIR}/usr/include/rpcsvc/nlm_prot.x .
	rm -f nlm_prot.h
	ln -s ${DESTDIR}/usr/include/rpcsvc/nlm_prot.h .
	rpcgen -C -L -m -o ${.TARGET} nlm_prot.x

test: ${.CURDIR}/test.c
	cc -o test ${.CURDIR}/test.c -lrpcsvc

.include <bsd.prog.mk>
