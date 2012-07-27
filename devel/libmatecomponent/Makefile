# New ports collection makefile for:   libbonobo
# Date Created:			14 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/devel/libmatecomponent/Makefile,v 1.3 2012/07/26 04:37:52 mezz Exp $
#

PORTNAME=	libmatecomponent
PORTVERSION=	1.4.0
CATEGORIES=	devel mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A component and compound document system for MATE

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

USE_XZ=		yes
USE_MATE=	autogen common:build corba intlhack ltverhack matehack
USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	glib20 libxml2
USE_PERL5=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		matecomponent-activation-server.1

.include <bsd.port.mk>
