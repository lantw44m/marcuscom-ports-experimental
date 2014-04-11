# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	libgit2-glib
PORTVERSION=	0.0.12
CATEGORIES=	devel gnome
MASTER_SITES=	https://git.gnome.org/browse/libgit2-glib/snapshot/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib wrapper library around the libgit2 git access library

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libgit2.so:${PORTSDIR}/devel/libgit2

USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomeprefix gtk30 intlhack introspection
USE_AUTOTOOLS=	automake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgit2-glib-1.0.so.0

.include <bsd.port.mk>
