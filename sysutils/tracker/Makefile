# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	tracker
PORTVERSION=	1.0.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libgxps.so:${PORTSDIR}/graphics/libgxps \
		libwv-1.2.so:${PORTSDIR}/textproc/wv \
		libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libexempi.so:${PORTSDIR}/textproc/exempi \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libraptor.so:${PORTSDIR}/textproc/raptor \
		libogg.so:${PORTSDIR}/audio/libogg \
		libiptcdata.so:${PORTSDIR}/graphics/libiptcdata \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		librest-0.7.so:${PORTSDIR}/devel/librest \
		libmediaart-1.0.so:${PORTSDIR}/multimedia/libmediaart \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libcue.so:${PORTSDIR}/textproc/libcue \
		libtag.so:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	xdg-desktop-icon:${PORTSDIR}/devel/xdg-utils \
		o3totxt:${PORTSDIR}/converters/o3read \
		pdftotext:${PORTSDIR}/graphics/poppler-utils \
		w3m:${PORTSDIR}/www/w3m

PLIST_SUB=	TRACKER_VER="1.0"

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intltool introspection:build
USE_LDCONFIG=	yes
USE_SQLITE=	3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/tracker
CONFIGURE_ARGS=	--enable-video-extractor=gstreamer \
		--with-session-bus-services-dir=${LOCALBASE}/share/dbus-1/services \
		--enable-libexif --enable-libgxps \
		--enable-libiptcdata --enable-miner-fs \
		--disable-meegotouch  --disable-miner-flickr \
	 	--enable-taglib \
		--enable-tracker-preferences --enable-poppler \
		--enable-libgsf \
		--disable-libosinfo --enable-libgif \
		--enable-libjpeg --enable-libtiff \
		--enable-libvorbis --enable-libflac \
		--enable-libcue \
		--enable-generic-media-extractor=gstreamer
GLIB_SCHEMAS=	org.freedesktop.Tracker.DB.gschema.xml \
		org.freedesktop.Tracker.Extract.gschema.xml \
		org.freedesktop.Tracker.FTS.gschema.xml \
		org.freedesktop.Tracker.Miner.Files.gschema.xml \
		org.freedesktop.Tracker.Store.gschema.xml \
		org.freedesktop.Tracker.Writeback.gschema.xml \
		org.freedesktop.Tracker.enums.xml \
		org.freedesktop.Tracker.gschema.xml

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng15|' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtracker-*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtracker-*.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tracker-1.0/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tracker-1.0/*/*.so*

.include <bsd.port.post.mk>
