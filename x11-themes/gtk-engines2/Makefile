# New ports collection makefile for:	gtk-engines2
# Date Created:				21 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11-themes/gtk-engines2/Makefile,v 1.1 2006/02/15 22:26:55 marcus Exp $
#

PORTNAME=	gtk-engines2
PORTVERSION=	2.7.4
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.7
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the gtk+-2.0 toolkit

CONFLICTS=	gtk-smooth-engine-[0-9]* clearlooks-[0-9]*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtk20
PLIST_SUB=	GTK_VERSION="2.4.0"

# Disable the gtk1 theme.
post-patch:
	@${REINPLACE_CMD} -e 's|gtk gtk-2.0|gtk-2.0|g' \
		${WRKSRC}/themes/Redmond/Makefile.in

.include <bsd.port.mk>
