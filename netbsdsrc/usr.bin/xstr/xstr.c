/*	$NetBSD: xstr.c,v 1.7 1997/10/20 01:21:46 mrg Exp $	*/

/*
 * Copyright (c) 1980, 1993
 *	The Regents of the University of California.  All rights reserved.
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
 */

#include <sys/cdefs.h>
#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 1980, 1993\n\
	The Regents of the University of California.  All rights reserved.\n");
#endif /* not lint */

#ifndef lint
#if 0
static char sccsid[] = "@(#)xstr.c	8.1 (Berkeley) 6/9/93";
#else
__RCSID("$NetBSD: xstr.c,v 1.7 1997/10/20 01:21:46 mrg Exp $");
#endif
#endif /* not lint */

#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pathnames.h"

/*
 * xstr - extract and hash strings in a C program
 *
 * Bill Joy UCB
 * November, 1978
 */

#define	ignore(a)	((void) a)

off_t	tellpt;
off_t	hashit __P((char *, int));
void	onintr __P((int));
off_t	yankstr __P((char **));
int	octdigit __P((char));
void	inithash __P((void));
int	fgetNUL __P((char *, int, FILE *));
int	xgetc __P((FILE *));
void	flushsh __P((void));
void	found __P((int, off_t, char *));
void	prstr __P((char *));
void	xsdotc __P((void));
char	lastchr __P((char *));
int	istail __P((char *, char *));
void	process __P((char *));

off_t	mesgpt;
char	*strings =	"strings";

char	*array =	0;

int	cflg;
int	vflg;
int	readstd;
int	main __P((int, char *[]));

int
main(argc, argv)
	int argc;
	char *argv[];
{
	int c;

	while ((c = getopt(argc, argv, "-cvl:")) != -1)
		switch (c) {
		case '-':
			readstd++;
			break;
		case 'c':
			cflg++;
			break;
		case 'v':
			vflg++;
			break;
		case 'l':
			array = optarg;
			break;
		default:
			fprintf(stderr, "usage: xstr [ -v ] [ -c ] [ -l array ] [ - ] [ name ... ]\n");
			exit (1);
		}
	argc -= optind;
	argv += optind;

	if (array == 0)
		array = "xstr";

	if (signal(SIGINT, SIG_IGN) == SIG_DFL)
		signal(SIGINT, onintr);
	if (cflg || (argc == 0 && !readstd))
		inithash();
	else
		strings = mktemp(strdup(_PATH_TMP));
	while (readstd || argc > 0) {
		if (freopen("x.c", "w", stdout) == NULL)
			perror("x.c"), exit(1);
		if (!readstd && freopen(argv[0], "r", stdin) == NULL)
			perror(argv[0]), exit(2);
		process("x.c");
		if (readstd == 0)
			argc--, argv++;
		else
			readstd = 0;
	};
	flushsh();
	if (cflg == 0)
		xsdotc();
	if (strings[0] == '/')
		ignore(unlink(strings));
	exit(0);
}

char linebuf[BUFSIZ];

void
process(name)
	char *name;
{
	char *cp;
	int c;
	int incomm = 0;
	int ret;

	printf("extern char\t%s[];\n", array);
	for (;;) {
		if (fgets(linebuf, sizeof linebuf, stdin) == NULL) {
			if (ferror(stdin)) {
				perror(name);
				exit(3);
			}
			break;
		}
		if (linebuf[0] == '#') {
			if (linebuf[1] == ' ' && isdigit(linebuf[2]))
				printf("#line%s", &linebuf[1]);
			else
				printf("%s", linebuf);
			continue;
		}
		for (cp = linebuf; (c = *cp++);) switch (c) {

		case '"':
			if (incomm)
				goto def;
			if ((ret = (int) yankstr(&cp)) == -1)
				goto out;
			printf("(&%s[%d])", array, ret);
			break;

		case '\'':
			if (incomm)
				goto def;
			putchar(c);
			if (*cp)
				putchar(*cp++);
			break;

		case '/':
			if (incomm || *cp != '*')
				goto def;
			incomm = 1;
			cp++;
			printf("/*");
			continue;

		case '*':
			if (incomm && *cp == '/') {
				incomm = 0;
				cp++;
				printf("*/");
				continue;
			}
			goto def;

def:
		default:
			putchar(c);
			break;
		}
	}
out:
	if (ferror(stdout))
		perror("x.c"), onintr(0);
}

off_t
yankstr(cpp)
	char **cpp;
{
	char *cp = *cpp;
	int c, ch;
	char dbuf[BUFSIZ];
	char *dp = dbuf;
	char *tp;

	while ((c = *cp++)) {
		switch (c) {

		case '"':
			cp++;
			goto out;

		case '\\':
			c = *cp++;
			if (c == 0)
				break;
			if (c == '\n') {
				if (fgets(linebuf, sizeof linebuf, stdin)
				    == NULL) {
					if (ferror(stdin)) {
						perror("x.c");
						exit(3);
					}
					return(-1);
				}
				cp = linebuf;
				continue;
			}
			for (tp = "b\bt\tr\rn\nf\f\\\\\"\""; (ch = *tp++); tp++)
				if (c == ch) {
					c = *tp;
					goto gotc;
				}
			if (!octdigit(c)) {
				*dp++ = '\\';
				break;
			}
			c -= '0';
			if (!octdigit(*cp))
				break;
			c <<= 3, c += *cp++ - '0';
			if (!octdigit(*cp))
				break;
			c <<= 3, c += *cp++ - '0';
			break;
		}
gotc:
		*dp++ = c;
	}
out:
	*cpp = --cp;
	*dp = 0;
	return (hashit(dbuf, 1));
}

int
octdigit(c)
	char c;
{

	return (isdigit(c) && c != '8' && c != '9');
}

void
inithash()
{
	char buf[BUFSIZ];
	FILE *mesgread = fopen(strings, "r");

	if (mesgread == NULL)
		return;
	for (;;) {
		mesgpt = tellpt;
		if (fgetNUL(buf, sizeof buf, mesgread) == 0)
			break;
		ignore(hashit(buf, 0));
	}
	ignore(fclose(mesgread));
}

int
fgetNUL(obuf, rmdr, file)
	char *obuf;
	int rmdr;
	FILE *file;
{
	int c;
	char *buf = obuf;

	while (--rmdr > 0 && (c = xgetc(file)) != 0 && c != EOF)
		*buf++ = c;
	*buf++ = 0;
	return ((feof(file) || ferror(file)) ? 0 : 1);
}

int
xgetc(file)
	FILE *file;
{

	tellpt++;
	return (getc(file));
}

#define	BUCKETS	128

struct	hash {
	off_t	hpt;
	char	*hstr;
	struct	hash *hnext;
	short	hnew;
} bucket[BUCKETS];

off_t
hashit(str, new)
	char *str;
	int new;
{
	int i;
	struct hash *hp, *hp0;

	hp = hp0 = &bucket[lastchr(str) & 0177];
	while (hp->hnext) {
		hp = hp->hnext;
		i = istail(str, hp->hstr);
		if (i >= 0)
			return (hp->hpt + i);
	}
	if ((hp = (struct hash *) calloc(1, sizeof (*hp))) == NULL) {
		perror("xstr");
		exit(8);
	}
	hp->hpt = mesgpt;
	if (!(hp->hstr = strdup(str))) {
		(void)fprintf(stderr, "xstr: %s\n", strerror(errno));
		exit(1);
	}
	mesgpt += strlen(hp->hstr) + 1;
	hp->hnext = hp0->hnext;
	hp->hnew = new;
	hp0->hnext = hp;
	return (hp->hpt);
}

void
flushsh()
{
	int i;
	struct hash *hp;
	FILE *mesgwrit;
	int old = 0, new = 0;

	for (i = 0; i < BUCKETS; i++)
		for (hp = bucket[i].hnext; hp != NULL; hp = hp->hnext)
			if (hp->hnew)
				new++;
			else
				old++;
	if (new == 0 && old != 0)
		return;
	mesgwrit = fopen(strings, old ? "r+" : "w");
	if (mesgwrit == NULL)
		perror(strings), exit(4);
	for (i = 0; i < BUCKETS; i++)
		for (hp = bucket[i].hnext; hp != NULL; hp = hp->hnext) {
			found(hp->hnew, hp->hpt, hp->hstr);
			if (hp->hnew) {
				fseek(mesgwrit, hp->hpt, 0);
				ignore(fwrite(hp->hstr, strlen(hp->hstr) + 1, 1, mesgwrit));
				if (ferror(mesgwrit))
					perror(strings), exit(4);
			}
		}
	if (fclose(mesgwrit) == EOF)
		perror(strings), exit(4);
}

void
found(new, off, str)
	int new;
	off_t off;
	char *str;
{
	if (vflg == 0)
		return;
	if (!new)
		fprintf(stderr, "found at %d:", (int) off);
	else
		fprintf(stderr, "new at %d:", (int) off);
	prstr(str);
	fprintf(stderr, "\n");
}

void
prstr(cp)
	char *cp;
{
	int c;

	while ((c = (*cp++ & 0377)))
		if (c < ' ')
			fprintf(stderr, "^%c", c + '`');
		else if (c == 0177)
			fprintf(stderr, "^?");
		else if (c > 0200)
			fprintf(stderr, "\\%03o", c);
		else
			fprintf(stderr, "%c", c);
}

void
xsdotc()
{
	FILE *strf = fopen(strings, "r");
	FILE *xdotcf;

	if (strf == NULL)
		perror(strings), exit(5);
	xdotcf = fopen("xs.c", "w");
	if (xdotcf == NULL)
		perror("xs.c"), exit(6);
	fprintf(xdotcf, "char\t%s[] = {\n", array);
	for (;;) {
		int i, c;

		for (i = 0; i < 8; i++) {
			c = getc(strf);
			if (ferror(strf)) {
				perror(strings);
				onintr(0);
			}
			if (feof(strf)) {
				fprintf(xdotcf, "\n");
				goto out;
			}
			fprintf(xdotcf, "0x%02x,", c);
		}
		fprintf(xdotcf, "\n");
	}
out:
	fprintf(xdotcf, "};\n");
	ignore(fclose(xdotcf));
	ignore(fclose(strf));
}

char
lastchr(cp)
	char *cp;
{

	while (cp[0] && cp[1])
		cp++;
	return (*cp);
}

int
istail(str, of)
	char *str, *of;
{
	int d = strlen(of) - strlen(str);

	if (d < 0 || strcmp(&of[d], str) != 0)
		return (-1);
	return (d);
}

void
onintr(dummy)
	int dummy;
{

	ignore(signal(SIGINT, SIG_IGN));
	if (strings[0] == '/')
		ignore(unlink(strings));
	ignore(unlink("x.c"));
	ignore(unlink("xs.c"));
	exit(7);
}
