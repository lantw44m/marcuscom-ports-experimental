# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	libmediaart
PORTVERSION=	0.2.0
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmediaart-1.0.so.200

.include <bsd.port.mk>
