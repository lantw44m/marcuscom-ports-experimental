# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	gcr
PORTVERSION=	3.11.91
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing

BUILD_DEPENDS=	gtk-doc>0:${PORTSDIR}/textproc/gtk-doc \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libp11-kit.so:${PORTSDIR}/security/p11-kit \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFLICTS=	gnome-keyring-2.[0-9]*

USE_GNOME=	gtk30 gnomehier intlhack introspection:build
USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
