# platform_irix6.x_common.GNU,v 4.2 2000/10/31 14:32:16 cleeland Exp

xt_reactor = 1
exceptions = 1

PLATFORM_XT_CPPFLAGS=
PLATFORM_XT_LIBS=-lXm -lXt -lX11
PLATFORM_XT_LDFLAGS=

ifndef ACE_IRIX_VERS
ACE_IRIX_VERS       := $(subst .,,$(shell uname -r))
endif # ACE_IRIX_VERS

CPPFLAGS += -DACE_IRIX_VERS=$(ACE_IRIX_VERS)
