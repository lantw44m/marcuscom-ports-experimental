# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom$

PORTNAME=	sushi
PORTVERSION=	3.11.90
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tool similar to Gloobus Preview that provides quick file previews

LIB_DEPENDS=	libgcr-3.so:${PORTSDIR}/security/gcr \
		libgjs.so:${PORTSDIR}/lang/gjs \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libmusicbrainz5.so:${PORTSDIR}/audio/libmusicbrainz5 \
		libevdocument3.so:${PORTSDIR}/graphics/evince
RUN_DEPENDS=	nautilus:${PORTSDIR}/x11-fm/nautilus

USES=		gettext gmake pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gtksourceview3 intlhack introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sushi/libsushi-1.0.so

.include <bsd.port.mk>
