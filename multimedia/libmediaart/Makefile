# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/multimedia/libmediaart/Makefile 19154 2014-03-16 11:08:48Z gusi $

PORTNAME=	libmediaart
PORTVERSION=	0.3.0
CATEGORIES=	multimedia devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for handling media art

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		vala>=0:${PORTSDIR}/lang/vala \
		vapigen:${PORTSDIR}/lang/vala-vapigen

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--enable-gtk-doc \
		--enable-introspection \
		--enable-vala
USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 glib20 gnomedocutils introspection

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmediaart-1.0.so.300

.include <bsd.port.mk>
