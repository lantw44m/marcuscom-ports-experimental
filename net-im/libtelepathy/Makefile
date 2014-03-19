# $FreeBSD$
#    $MCom$

PORTNAME=	libtelepathy
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Flexible Communications Framework

LIB_PC_DEPENDS=	dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

USE_PYTHON_BUILD=	yes
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 ltverhack
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
