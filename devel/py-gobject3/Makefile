# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTREVISION=	0

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

SLAVE_PORT=	python2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo \
		pygobject3-common>=0:${PORTSDIR}/devel/pygobject3-common

USE_GNOME=	glib20 introspection
USE_PYTHON=	2
USE_LDCONFIG=	yes
MASTERDIR=	${.CURDIR}/../../devel/pygobject3-common
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
