# New ports collection makefile for:	gnome-menus
# Date created:				30 November 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate-menus/Makefile,v 1.2 2012/07/26 04:37:54 mezz Exp $
#

PORTNAME=	mate-menus
PORTVERSION=	1.4.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_XZ=		yes
USE_MATE=	autogen common:build intlhack ltverhack matehack
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/mate|${LOCALBASE}/share/mate|g' \
		${WRKSRC}/layout/mate-applications.menu \
		${WRKSRC}/layout/mate-settings.menu
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/KDE.directory > ${WRKSRC}/KDE.directory

post-install:
	@${INSTALL_DATA} ${WRKSRC}/KDE.directory \
		${PREFIX}/share/mate/desktop-directories/

.include <bsd.port.mk>
