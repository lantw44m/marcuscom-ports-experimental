# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/multimedia/clutter-gst/Makefile 19077 2014-03-11 11:16:22Z gusi $

PORTNAME=	clutter-gst
PORTVERSION=	2.0.10
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GL=		gl
USES=		gmake pathfix pkgconfig
USE_GNOME=	introspection gnomehier gnomeprefix ltverhack
USE_GSTREAMER1=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgstclutter.so
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libclutter-gst-2.0.so.0

.include <bsd.port.mk>
