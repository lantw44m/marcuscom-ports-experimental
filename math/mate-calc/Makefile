# New ports collection makefile for:	gcalctool
# Date created:				12 Jun 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	mate-calc
PORTVERSION=	1.4.0
CATEGORIES=	math mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MATE calculator tool based on the old calctool for OpenWindows

USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack matehack
USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 libxml2
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_PKGCONFIG=	build
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-calc.1
GLIB_SCHEMAS=	org.mate.mate-calc.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|$$(LEX)|${LOCALBASE}/bin/flex|g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
