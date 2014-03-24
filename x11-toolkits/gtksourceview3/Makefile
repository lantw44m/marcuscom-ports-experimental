# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gtksourceview
PORTVERSION=	3.12.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build \
		libxml2 ltverhack referencehack
CONFIGURE_ARGS=	--enable-compile-warnings=no --enable-glade-catalog=no \
		--enable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|--warn-all||g' \
		${WRKSRC}/gtksourceview/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtksourceview-3.0.so.1

.include <bsd.port.mk>

.endif
