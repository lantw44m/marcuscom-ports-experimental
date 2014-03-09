# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	atkmm
PORTVERSION=	2.22.7
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for ATK API library

USES=		gmake pathfix pkgconfig
USE_XZ=		yes
USE_LDCONFIG=	yes
USE_GNOME=	atk glibmm
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
