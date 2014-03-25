# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/games/swell-foop/Makefile 19176 2014-03-18 08:02:45Z gusi $

PORTNAME=	swell-foop
PORTVERSION=	3.12.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome swell-foop

BUILD_DEPENDS=	vala:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3

USES=		gettext gmake pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
USE_GL=		gl
USE_GNOME=	gtk30 intlhack libxml2:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.swell-foop.gschema.xml

.include <bsd.port.mk>
