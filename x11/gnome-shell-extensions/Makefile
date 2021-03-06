# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	gnome-shell-extensions
PORTVERSION=	3.12.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME desktop shell extensions

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	gnome-shell>=3.6.2:${PORTSDIR}/x11/gnome-shell

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomedesktop3 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extensions=all

GLIB_SCHEMAS=	org.gnome.shell.extensions.auto-move-windows.gschema.xml \
		org.gnome.shell.extensions.classic-overrides.gschema.xml \
		org.gnome.shell.extensions.example.gschema.xml \
		org.gnome.shell.extensions.native-window-placement.gschema.xml \
		org.gnome.shell.extensions.user-theme.gschema.xml \
		org.gnome.shell.extensions.window-list.gschema.xml

.include <bsd.port.mk>
