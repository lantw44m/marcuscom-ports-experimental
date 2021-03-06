# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/sysutils/upower/Makefile 19080 2014-03-11 13:36:04Z gusi $

PORTNAME=	upower
PORTVERSION=	0.99.0
CATEGORIES=	sysutils
MASTER_SITES=	http://upower.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	intlhack glib20 introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	GTKDOC="false"

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
PLIST_SUB+=	MAN="@comment "
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt:build
PLIST_SUB+=	MAN=""
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
