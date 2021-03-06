# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/graphics/libchamplain/Makefile 19060 2014-03-10 14:08:01Z gusi $

PORTNAME=	libchamplain
PORTVERSION=	0.12.7
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library aimed to provide a Gtk+ widget to display rasterized maps and markers

LIB_DEPENDS=	libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 gnomehier introspection:build
USE_GL=		gl
USE_SQLITE=	3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-gtk-doc-html=no

PLIST_SUB=	VERSION=0.12

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_MODULE = libchamplain|DOC_MODULE = libchamplain-gtk3|g' \
		${WRKSRC}/docs/reference/Makefile.in \
		${WRKSRC}/docs/reference-gtk/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libchamplain*.so*

.include <bsd.port.mk>
