# New ports collection makefile for:	gnomecommon
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/devel/mate-common/Makefile,v 1.1 2012/07/06 02:48:06 mezz Exp $
#

PORTNAME=	mate-common
PORTVERSION=	1.4.0
CATEGORIES=	devel mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for MATE

USE_XZ=		yes
USE_MATE=	autogen
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
GNU_CONFIGURE=	yes

MAN1=		mate-autogen.1 mate-doc-common.1

.include <bsd.port.mk>
