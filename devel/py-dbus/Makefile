# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	dbus
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel gnome python
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python2 bindings for the D-BUS messaging system

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	pydbus-common>=0:${PORTSDIR}/devel/pydbus-common

USES=		gettext pathfix pkgconfig gmake
USE_PYTHON=	2
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--disable-api-docs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_dbus_*bindings.so

	@${RM} -f ${STAGEDIR}${PREFIX}/include/dbus-1.0/dbus/dbus-python.h \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/dbus-python.pc
	@${RM} -f ${STAGEDIR}${DOCSDIR}/*
	@${RMDIR} ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
