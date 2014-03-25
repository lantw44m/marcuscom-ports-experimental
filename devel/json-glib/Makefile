# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	json-glib
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix introspection
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libjson-glib-1.0.so.0

.include <bsd.port.mk>
