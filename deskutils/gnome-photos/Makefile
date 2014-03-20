# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-photos
PORTVERSION=	3.11.91
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photo application for GNOME 3

BUILD_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libexempi.so:${PORTSDIR}/textproc/exempi \
		libgfbgraph-0.2.so:${PORTSDIR}/net/gfbgraph \
		libgegl-0.2.so:${PORTSDIR}/graphics/gegl \
		libgrilo-0.2.so:${PORTSDIR}/net/grilo \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker \
		libgjs.so:${PORTSDIR}/lang/gjs \
		libbabl-0.1.so:${PORTSDIR}/x11/babl
RUN_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue

USES=		desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
