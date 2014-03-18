# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom$

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
CONFIGURE_ARGS=	--disable-bluez-backend
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=deprecated-declarations
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=41

OPTIONS_DEFINE=	SOCIALWEB TRACKER
OPTIONS_DEFAULT=SOCIALWEB TRACKER
SOCIALWEB_DESC=	Social web backend
TRACKER_DESC=	Tracker backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOCIALWEB}
LIB_DEPENDS+=	libsocialweb.so:${PORTSDIR}/www/libsocialweb
CONFIGURE_ARGS+=--enable-libsocialweb-backend
PLIST_SUB+=	SOCIAL=""
.else
CONFIGURE_ARGS+=--disable-libsocialweb-backend
PLIST_SUB+=	SOCIAL="@comment "
.endif

.if ${PORT_OPTIONS:MTRACKER}
LIB_DEPENDS+=   libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker
CONFIGURE_ARGS+=--enable-tracker-backend
PLIST_SUB+=     TRACKER=""
.else
CONFIGURE_ARGS+=--disable-tracker-backend
PLIST_SUB+=     TRACKER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|g' \
		${WRKDIR}/gnome-libtool
	@${REINPLACE_CMD} -e 's|TRACKER_SPARQL_MAJOR=0.16|TRACKER_SPARQL_MAJOR=1.0|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|--fatal-warnings||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfolks*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/folks/*/backends/*/*.so

.include <bsd.port.mk>
