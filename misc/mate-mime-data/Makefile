# New ports collection makefile for:	gnomemimedata
# Date created:				22 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/misc/mate-mime-data/Makefile,v 1.1 2012/07/06 02:48:08 mezz Exp $
#

PORTNAME=	mate-mime-data
PORTVERSION=	1.2.2
CATEGORIES=	misc mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MIME and Application database for MATE

USE_XZ=		yes
USE_MATE=	autogen intlhack matehack
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GETTEXT=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
