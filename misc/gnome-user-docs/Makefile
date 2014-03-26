# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-user-docs
PORTVERSION=	3.12.0
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 users guide

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

GNU_CONFIGURE=	yes
#MAKE_JOBS_UNSAFE=yes
USES=		gettext:build gmake pathfix tar:xz
USE_GNOME=	gnomeprefix gnomehier libxml2:build

.include <bsd.port.mk>
