# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	clutter-gst
PORTVERSION=	2.0.10
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

USES=		gmake pathfix pkgconfig tar:xz
USE_GNOME=	introspection gnomehier gnomeprefix ltverhack
USE_AUTOTOOLS=	libtool
USE_GL=		gl
USE_GSTREAMER1=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgstclutter.so
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libclutter-gst-2.0.so.0

.include <bsd.port.mk>
