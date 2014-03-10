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
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gtk30 introspection ltverhack
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
