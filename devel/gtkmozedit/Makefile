# New ports collection makefile for:	gtkmozedit
# Date created:		2005-10-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD: ports/devel/gtkmozedit/Makefile,v 1.13 2007/10/04 00:41:07 edwin Exp $
#

PORTNAME=	gtkmozedit
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	devel editors www
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text editor widget based on Mozilla's editing functionality

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_GECKO=	mozilla

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|firefox-nspr|firefox-xpcom|; \
		s|mozilla-nspr|mozilla-xpcom|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
