# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gucharmap
PORTVERSION=	3.12.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USES=		desktop-file-utils gettext gmake pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-Bsymbolic
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Charmap.enums.xml org.gnome.Charmap.gschema.xml

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgucharmap_2_90.so.7

.include <bsd.port.mk>

