# Created by: Jeremy Messenger <mezz@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.12.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3 / GNOME3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gconf2 gnomeprefix gtk30 py3gobject3
USE_PYTHON=	3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
