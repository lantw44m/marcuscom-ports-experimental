# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	pygobject
PORTVERSION=	3.12.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	3-common
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common files for the Python bindings for GObject

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo

USES=		gmake pathfix pkgconfig tar:xz
USE_PYTHON_BUILD=	2
USE_GNOME=	glib20:build introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# this port doesn't work with py-gobject < 2.28.6_2, clungle below
CONFLICTS=	py*-gtk-0* py*-gobject-2.*.[0-6] py*-gobject-2.*.[7-9] \
		py*-gobject-2.*.6_1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|SUBDIRS = examples gi tests|SUBDIRS = examples gi|g' \
		${WRKSRC}/Makefile.in

do-build:
	${DO_NADA}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pygobject-3.0/
	${INSTALL_DATA} ${WRKSRC}/gi/pygobject.h \
		${STAGEDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
	${INSTALL_DATA} ${WRKSRC}/pygobject-3.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc

.include <bsd.port.post.mk>
