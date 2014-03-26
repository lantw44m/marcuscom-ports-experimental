# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gobject
PORTVERSION=	3.12.0
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GObject

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/py3cairo.pc:${PORTSDIR}/graphics/py3-cairo
LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/py3cairo.pc:${PORTSDIR}/graphics/py3-cairo

USES=		gmake pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection
USE_PYTHON=	3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# this port doesn't work with py-gobject < 2.28.6_2, clungle below
CONFLICTS=	py*-gtk-0* py*-gobject-2.*.[0-6] py*-gobject-2.*.[7-9] \
		py*-gobject-2.*.6_1

PLIST_SUB=	PYTHON_VER="${PYTHON_VER}" ARCH=${ARCH} UNAME_R=${UNAME_R} \
		VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

UNAME_R!=	${UNAME} -r

post-patch:
	@${REINPLACE_CMD} -e 's|SUBDIRS = examples gi tests|SUBDIRS = examples gi|g' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gi/*.so
	

.include <bsd.port.post.mk>
