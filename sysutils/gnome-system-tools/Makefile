# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/gnome-system-tools/Makefile,v 1.43 2006/07/21 20:46:59 mezz Exp $

PORTNAME=	gnome-system-tools
PORTVERSION=	2.15.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-tools/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-system-tools-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

LIB_DEPENDS=	oobs-1.0:${PORTSDIR}/devel/liboobs

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack nautilus2
USE_AUTOTOOLS=	libtool:15
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-services
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-system-tools.schemas

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	uses symbols not present in 4.X
.endif

.include <bsd.port.post.mk>
