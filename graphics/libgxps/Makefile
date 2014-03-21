# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	libgxps
PORTVERSION=	0.2.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject based library for rendering XPS documents

BUILD_DEPENDS=	libarchive>=0:${PORTSDIR}/archivers/libarchive
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		liblcms2.so:${PORTSDIR}/graphics/lcms2
RUN_DEPENDS=	libarchive>=0:${PORTSDIR}/archivers/libarchive

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gnomeprefix glib20 intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
