# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	telepathy-mission-control
PORTVERSION=	5.16.1
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-mission-control/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Telepathy component to apps to abstract details of connection managers

LIB_DEPENDS=	libtelepathy.so:${PORTSDIR}/net-im/libtelepathy \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gmake pathfix pathfix pkgconfig
USE_GNOME=	gconf2 libxslt ltverhack
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	im.telepathy.MissionControl.FromEmpathy.gschema.xml

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMP} ${STAGEDIR}${PREFIX}/lib/libmission-control-plugins.so.0 

.include <bsd.port.mk>
