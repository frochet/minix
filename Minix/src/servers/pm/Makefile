# Makefile for Process Manager (PM)
PROG=	pm
SRCS=	main.c forkexit.c break.c exec.c time.c alarm.c \
<<<<<<< HEAD
	signal.c utility.c table.c trace.c getset.c misc.c \
	profile.c dma.c mcontext.c schedule.c pm_limit.c
=======
	rlimit.c signal.c utility.c table.c trace.c getset.c misc.c \
	profile.c dma.c mcontext.c schedule.c 
>>>>>>> 20269366a606e298c9393047ddb8cbcd138710de

DPADD+=	${LIBSYS} ${LIBTIMERS}
LDADD+=	-lsys -ltimers

MAN=

BINDIR?= /usr/sbin
INSTALLFLAGS+=	-S 32k

CPPFLAGS.main.c+=	-I${MINIXSRCDIR}
CPPFLAGS.misc.c+=	-I${MINIXSRCDIR}
CPPFLAGS.schedule.c+=	-I${MINIXSRCDIR}
CPPFLAGS.utility.c+=	-I${MINIXSRCDIR}

.include <bsd.prog.mk>
