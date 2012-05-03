# New ports collection makefile for:	gdk-pixbuf
# Date created:		5th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#    $MCom: ports/graphics/gdk-pixbuf2/Makefile,v 1.18 2011/12/17 16:54:22 kwm Exp $

PORTNAME?=	gdk-pixbuf
PORTVERSION=	2.26.1
CATEGORIES?=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gdk-pixbuf/${PORTVERSION:R}
DISTNAME=	gdk-pixbuf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A graphic library for GTK+

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		jasper.4:${PORTSDIR}/graphics/jasper

LATEST_LINK=	gdk-pixbuf2
USE_XZ=		yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME+=	gnomehack glib20 ltverhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=yes --with-libjasper

MAN1=		gdk-pixbuf-csource.1 gdk-pixbuf-query-loaders.1

post-install:
	@cd ${WRKSRC}/docs/reference/gdk-pixbuf && gmake install-man1

.if !defined(WITHOUT_X11)
USE_XORG=	xt xi x11
CONFIGURE_ARGS+=--with-x11
PLIST_SUB+=	XLIB=""
.else
CONFIGURE_ARGS+=--without-x11
PLIST_SUB+=	XLIB="@comment "
.endif

.include <bsd.port.mk>
