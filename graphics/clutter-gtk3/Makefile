# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	clutter-gtk
PORTVERSION=	1.5.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

LATEST_LINK=	clutter-gtk3
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gtk30 introspection
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libclutter-gtk-1.0.so.*

.include <bsd.port.mk>
