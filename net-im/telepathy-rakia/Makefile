# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom$

PORTNAME=	telepathy-rakia
PORTVERSION=	0.8.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SIP connection manager based around the Sofia-SIP library

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsofia-sip-ua-glib.so:${PORTSDIR}/net/sofia-sip \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_PYTHON_BUILD=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
