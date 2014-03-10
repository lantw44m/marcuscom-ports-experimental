# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	gjs
PORTVERSION=	1.39.91
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmozjs-24.so:${PORTSDIR}/lang/spidermonkey24

CONFLICTS_BUILD=spidermonkey17-1.7.* spidermonkey185-1.8.*

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig shebangfix
USE_PYTHON_BUILD=yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo glib20 gnomeprefix introspection:build \
		intlhack ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

#SHEBANG_FILES=	scripts/make-tests
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgjs.so.0

.include <bsd.port.mk>
