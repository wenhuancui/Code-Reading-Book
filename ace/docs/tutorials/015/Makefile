
# Makefile,v 1.8 1999/06/22 18:40:59 levine Exp

#----------------------------------------------------------------------------
#	Local macros
#----------------------------------------------------------------------------

BIN    = client server

all clean realclean : #
	$(MAKE) -f Makefile.client $@
	$(MAKE) -f Makefile.server $@

client server : #
	$(MAKE) -f Makefile.$@ all

Depend : #
	$(MAKE) -f Makefile.client $@

HTML : #
	[ -f hdr ] || $(MAKE) UNSHAR
	perl ../combine *.pre
	chmod +r *.html

SHAR : #
	[ ! -f combine.shar ] || exit 1
	shar -T hdr bodies *.pre *.pst > combine.shar && $(RM) hdr bodies *.pre *.pst

UNSHAR : #
	sh combine.shar

CLEAN : realclean
	$(RM) hdr bodies *.pre *.pst .depend*
