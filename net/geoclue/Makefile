# Created by: Gustau Perez i Querol <gustau.perez@gmail.com> 
# $FreeBSD$
#   $MCom$

PORTNAME=	geoclue
PORTVERSION=	1.99.3
CATEGORIES=	net devel gnome
MASTER_SITES=	http://www.freedesktop.org/software/geoclue/releases/1.99/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus service that provides location information

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
	
USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomehier intlhack ltverhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
