# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/net-im/folks/Makefile 19163 2014-03-17 10:08:55Z gusi $

PORTNAME=	folks
PORTVERSION=	0.9.6
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libzeitgeist-1.0.so:${PORTSDIR}/sysutils/libzeitgeist \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.4.[0-9]*

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 gnomehier intlhack \
		introspection:build ltverhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tracker-backend \
		--disable-bluez-backend
#		--disable-eds-backend
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=deprecated-declarations
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=41

OPTIONS_DEFINE=	SOCIALWEB
OPTIONS_DEFAULT=SOCIALWEB
SOCIALWEB_DESC=	Social web backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOCIALWEB}
LIB_DEPENDS+=	libsocialweb.so:${PORTSDIR}/www/libsocialweb
CONFIGURE_ARGS+=--enable-libsocialweb-backend=yes
PLIST_SUB+=	SOCIAL=""
.else
CONFIGURE_ARGS+=--enable-libsocialweb-backend=no
PLIST_SUB+=	SOCIAL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|g' \
		${WRKDIR}/gnome-libtool
	@${REINPLACE_CMD} -e 's|--fatal-warnings||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfolks*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/folks/*/backends/*/*.so

.include <bsd.port.mk>
