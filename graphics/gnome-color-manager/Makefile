# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-color-manager
PORTVERSION=	3.12.1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session framework for the GNOME desktop to manage color profiles

BUILD_DEPENDS=	docbook2man:${PORTSDIR}/textproc/docbook-utils \
		itstool:${PORTSDIR}/textproc/itstool \
		${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml
LIB_DEPENDS=	liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libcolord.so:${PORTSDIR}/graphics/colord \
		libcolord-gtk.so:${PORTSDIR}/graphics/colord-gtk \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libexif.so:${PORTSDIR}/graphics/libexif

USE_XORG=	xrandr
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack vte3
USES=		desktop-file-utils gettext gmake pathfix \
		pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-clutter=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	RAW
OPTIONS_DEFAULT=RAW

RAW_DESC=	Enable RAW EXIF support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRAW}
LIB_DEPENDS+=	libexiv2.so:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv=yes
PLIST_SUB+=	RAW=""
.else
CONFIGURE_ARGS+=--enable-exiv=no
PLIST_SUB+=	RAW="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g ; s|-Wempty-body||g ; \
		s|-Wignored-qualifiers||g ; s|-Wtype-limits||g ; \
		s|-Wmissing-parameter-type||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
