/*	$NetBSD: bw2.c,v 1.2 1997/04/09 04:43:52 jeremy Exp $	*/

/*
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This software was developed by the Computer Systems Engineering group
 * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and
 * contributed to Berkeley.
 *
 * All advertising materials mentioning features or use of this software
 * must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Lawrence Berkeley Laboratory.
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
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)bwtwo.c	8.1 (Berkeley) 6/11/93
 */

/*
 * black&white display (bw2) driver.
 *
 * Does not handle interrupts, even though they can occur.
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/device.h>
#include <sys/ioctl.h>
#include <sys/malloc.h>
#include <sys/mman.h>
#include <sys/proc.h>
#include <sys/tty.h>

#include <vm/vm.h>

#include <machine/autoconf.h>
#include <machine/cpu.h>
#include <machine/enable.h>
#include <machine/fbio.h>
#include <machine/idprom.h>

#include "fbvar.h"
#include "bw2reg.h"
#include "pfourreg.h"

cdev_decl(bw2);

/* per-display variables */
struct bw2_softc {
	struct	device sc_dev;		/* base device */
	struct	fbdevice sc_fb;		/* frame buffer device */
	int 	sc_phys;		/* display RAM (phys addr) */
};

/* autoconfiguration driver */
static void	bw2attach __P((struct device *, struct device *, void *));
static int	bw2match __P((struct device *, struct cfdata *, void *));

struct cfattach bwtwo_ca = {
	sizeof(struct bw2_softc), bw2match, bw2attach
};

struct cfdriver bwtwo_cd = {
	NULL, "bwtwo", DV_DULL
};

/* XXX we do not handle frame buffer interrupts */

static int  bw2gvideo __P((struct fbdevice *, void *));
static int	bw2svideo __P((struct fbdevice *, void *));

static struct fbdriver bw2fbdriver = {
	bw2open, bw2close, bw2mmap,
	fb_noioctl,
	bw2gvideo, bw2svideo,
	fb_noioctl, fb_noioctl, };

static int
bw2match(parent, cf, args)
	struct device *parent;
	struct cfdata *cf;
	void *args;
{
	struct confargs *ca = args;
	int x;

#if 0	/* XXX - Assume only one is in use anyway... */
	/*
	 * This driver only supports one unit because the
	 * system enable register is used for blanking.
	 */
	if (cf->cf_unit != 0)
		return (0);
#endif

	if (ca->ca_paddr == -1) {
		ca->ca_paddr = BW2_FB_PADDR;
	}

	/* The peek returns -1 on bus error. */
	x = bus_peek(ca->ca_bustype, ca->ca_paddr, 1);
	return (x != -1);
}

/*
 * Attach a display.  We need to notice if it is the console, too.
 */
static void
bw2attach(parent, self, args)
	struct device *parent, *self;
	void *args;
{
	struct bw2_softc *sc = (struct bw2_softc *)self;
	struct fbdevice *fb = &sc->sc_fb;
	struct confargs *ca = args;
	struct fbtype *fbt;

	sc->sc_phys = ca->ca_paddr;

	fb->fb_driver = &bw2fbdriver;
	fb->fb_private = sc;
	fb->fb_name = sc->sc_dev.dv_xname;
	fb->fb_pfour = bus_mapin(BUS_OBMEM, BW2_P4_PADDR, sizeof(u_int32_t));

	fbt = &fb->fb_fbtype;
	fbt->fb_type = FBTYPE_SUN2BW;
	fbt->fb_depth = 1;
	fbt->fb_cmsize = 0;

	fbt->fb_width = 1152;
	fbt->fb_height = 900;
	fbt->fb_size = BW2_FBSIZE;

	printf(" (%dx%d)\n", fbt->fb_width, fbt->fb_height);
	fb_attach(fb, 1);
}

int
bw2open(dev, flags, mode, p)
	dev_t dev;
	int flags, mode;
	struct proc *p;
{
	int unit = minor(dev);

	if (unit >= bwtwo_cd.cd_ndevs || bwtwo_cd.cd_devs[unit] == NULL)
		return (ENXIO);
	return (0);
}

int
bw2close(dev, flags, mode, p)
	dev_t dev;
	int flags, mode;
	struct proc *p;
{

	return (0);
}

int
bw2ioctl(dev, cmd, data, flags, p)
	dev_t dev;
	u_long cmd;
	caddr_t data;
	int flags;
	struct proc *p;
{
	struct bw2_softc *sc = bwtwo_cd.cd_devs[minor(dev)];

	return (fbioctlfb(&sc->sc_fb, cmd, data));
}

/*
 * Return the address that would map the given device at the given
 * offset, allowing for the given protection, or return -1 for error.
 */
int
bw2mmap(dev, off, prot)
	dev_t dev;
	int off, prot;
{
	struct bw2_softc *sc = bwtwo_cd.cd_devs[minor(dev)];

	if (off & PGOFSET)
		return (-1);
	if ((unsigned)off >= sc->sc_fb.fb_fbtype.fb_size)
		return (-1);
	/*
	 * I turned on PMAP_NC here to disable the cache as I was
	 * getting horribly broken behaviour with it on.
	 */
	return ((sc->sc_phys + off) | PMAP_NC);
}

/* FBIOGVIDEO: */
static int bw2gvideo(fb, data)
	struct fbdevice *fb;
	void *data;
{
	int *on = data, s;
	volatile u_int32_t *reg = fb->fb_pfour;

	s = splhigh();
	*on = (*reg & PFOUR_REG_VIDEO) ? 1 : 0;
	splx(s);

	return (0);
}

/* FBIOSVIDEO */
static int bw2svideo(fb, data)
	struct fbdevice *fb;
	void *data;
{
	int *on = data, s;
	volatile u_int32_t *reg = fb->fb_pfour;

	s = splhigh();
	if (*on)
		*reg |= PFOUR_REG_VIDEO;
	else
		*reg &= ~PFOUR_REG_VIDEO;
	splx(s);

	return(0);
}
