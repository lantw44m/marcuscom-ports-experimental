# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	gitg
PORTVERSION=	0.3.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME GUI client to view git repositories

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgit2-glib-1.0.so:${PORTSDIR}/devel/libgit2-glib \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas \
		libgtkspell3-3.so:${PORTSDIR}/textproc/gtkspell3 \
		libgee-0.8.so:${PORTSDIR}/devel/libgee

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 gtksourceview3 intlhack libxslt
USE_PYTHON=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
