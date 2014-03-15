# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom$

PORTNAME=	gnome-calculator
PORTVERSION=	3.11.91
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 calculator tool

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USES=		bison gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gconf2 gnomeprefix gtksourceview3 gtk30 intlhack libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.calculator.gschema.xml

.include <bsd.port.mk>
