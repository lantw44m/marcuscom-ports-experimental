# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	gstreamer1
PORTVERSION=	1.2.0
CATEGORIES=	multimedia python gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Python2 bindings for gstreamer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pathfix pkgconfig tar:bzip2
USE_GNOME=	pygobject3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	2
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE} ${PTHREAD_LIBS}
DISTINFO_FILE=	${.CURDIR}/../py3-gstreamer1/distinfo

.include <bsd.port.mk>
