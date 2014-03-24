# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/dconf-editor/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	dconf
PORTREVISION=	0
PKGNAMESUFFIX=	-editor

COMMENT=	configuration editor for dconf

DCONF_SLAVE=	editor

MASTERDIR=	${.CURDIR}/../dconf

PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/editor
INSTALL_WRKSRC=	${WRKSRC}/editor

.include "${MASTERDIR}/Makefile"
