# New ports collection makefile for:	libgnomeui
# Date created:				07 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	libmateui
PORTVERSION=	1.2.0
CATEGORIES=	x11-toolkits mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for the MATE GUI, a GNU desktop environment

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS+=	popt.0:${PORTSDIR}/devel/popt

USE_XZ=		yes
USE_MATE=	autogen canvas common:build componentui conf icontheme:run lib \
		libmatekeyring ltverhack matehack vfs
USE_XORG=	sm
USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk20 libglade2 libxml2 pango pkgconfig
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
