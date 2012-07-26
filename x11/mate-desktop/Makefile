# New ports collection makefile for:	gnomedesktop
# Date created:				13 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate-desktop/Makefile,v 1.2 2012/07/19 21:39:46 mezz Exp $
#

PORTNAME=	mate-desktop
PORTVERSION=	1.4.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for MATE

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils intlhack ltverhack matehack
USE_XORG=	x11 xrandr
USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk20 pkgconfig
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		--disable-desktop-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-about.1

.include <bsd.port.mk>
