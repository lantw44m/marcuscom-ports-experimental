# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	libmediaart
PORTVERSION=	0.4.0
CATEGORIES=	multimedia devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for handling media art

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		vala>=0:${PORTSDIR}/lang/vala \
		vapigen:${PORTSDIR}/lang/vala-vapigen

USES=		gmake pathfix pkgconfig tar:xz
USE_GNOME=	gdkpixbuf2 glib20 introspection
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--enable-gtk-doc \
		--enable-introspection \
		--enable-vala

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmediaart-1.0.so.396

.include <bsd.port.mk>
