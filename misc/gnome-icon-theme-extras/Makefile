# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-icon-theme-extras
PORTVERSION=	3.11.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional collection of icons for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_XZ=		yes
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	intlhack gtk-update-icon-cache
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-icon-mapping
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
