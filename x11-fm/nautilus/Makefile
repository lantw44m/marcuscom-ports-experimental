# Created by: ade, archie
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11-fm/nautilus/Makefile 19180 2014-03-18 10:27:10Z gusi $

PORTNAME=	nautilus
PORTVERSION=	3.11.90
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		ltverhack gvfs ltasneededhack introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-pthread"
CONFIGURE_ARGS=	--disable-packagekit

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

OPTIONS_DEFINE=	TRACKER
OPTIONS_DEFAULT=TRACKER
TRACKER_DESC=	Tracker support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTRACKER}
LIB_DEPENDS+=	libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker
CONFIGURE_ARGS+=--enable-tracker=yes
PLIST_SUB+=	TRACKER=""
.else
CONFIGURE_ARGS+=--enable-tracker=no
PLIST_SUB+=	TRACKER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnautilus-extension.so.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nautilus/extensions-3.0/libnautilus-sendto.so

.include <bsd.port.mk>
