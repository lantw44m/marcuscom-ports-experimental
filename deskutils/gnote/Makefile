# $FreeBSD$
#   $MCom$

PORTNAME=	gnote
PORTVERSION=	3.11.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ version of Tomboy, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GNOME=	gnomeprefix gtk30 intltool libxml2 libxslt \
		gnomedocutils gtkmm30
USES=		desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig tar:xz
GLIB_SCHEMAS=	org.gnome.gnote.gschema.xml
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-dbus-service-dir=${PREFIX}/share/dbus-1/services
DOCS=		AUTHORS ChangeLog NEWS README TODO

.include <bsd.port.options.mk>

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnote-3.11.so.1.0.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnote/addins/${PORTVERSION}/*.so

.include <bsd.port.mk>
