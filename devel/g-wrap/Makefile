# ex:ts=8
# Ports collection makefile for:	g-wrap
# Date created:		Jun 29, 2000
# Whom:			Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD: ports/devel/g-wrap/Makefile,v 1.31 2006/07/02 04:03:10 marcus Exp $
#

PORTNAME=	g-wrap
PORTVERSION=	1.9.6
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A tool for exporting C libraries into Scheme interpreters

BUILD_DEPENDS=	${LOCALBASE}/share/guile/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${LOCALBASE}/share/guile/slibcat:${PORTSDIR}/lang/slib-guile

INFO=		g-wrap

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"glib"|"glib-2.0"|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
