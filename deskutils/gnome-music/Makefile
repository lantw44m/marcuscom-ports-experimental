# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/deskutils/gnome-music/Makefile 19289 2014-03-24 20:18:05Z gusi $

PORTNAME=	gnome-music
PORTVERSION=	3.12.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgrilo-0.2.so:${PORTSDIR}/net/grilo

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack \
		introspection:build
GNU_CONFIGURE=	yes
USE_PYTHON=	3
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-music/libgd.so

.include <bsd.port.mk>
