#----------------------------------------------------------------------------
#	rules.common.GNU,v 4.2 2000/05/03 19:02:37 coryan Exp
#
#	Common targets
#----------------------------------------------------------------------------

all: 		all.nested all.local
debug:		debug.nested debug.local
profile:	profile.nested profile.local
install:	install.nested install.local
deinstall:	deinstall.nested deinstall.local
clean:		clean.nested clean.local
realclean:	realclean.nested realclean.local
clobber:	clobber.nested clobber.local
depend:		depend.nested depend.local
rcs_info:	rcs_info.nested rcs_info.local
idl_stubs:	idl_stubs.nested idl_stubs.local
