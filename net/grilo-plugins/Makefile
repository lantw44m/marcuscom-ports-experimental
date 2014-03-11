# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	grilo-plugins
PORTVERSION=	0.2.11
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgrilo-0.2.so:${PORTSDIR}/net/grilo

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomehier intlhack libxml2 ltverhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/grilo-0.2/
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/grilo-0.2/libgrl*.so

.include <bsd.port.mk>
