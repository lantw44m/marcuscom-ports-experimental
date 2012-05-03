# New ports collection makefile for:	atk
# Date Created:				14 May 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/atk/Makefile,v 1.118 2011/10/23 10:23:05 kwm Exp $
#

PORTNAME=	atk
PORTVERSION=	2.4.0
PORTREVISION?=	0
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME accessibility toolkit (ATK)

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehier gnomehack glib20 ltverhack referencehack
CONFIGURE_ARGS=	--enable-static \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		AUTOCONF=${TRUE} AUTOMAKE=${TRUE}

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests docs//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
