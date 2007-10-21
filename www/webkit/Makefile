# New ports collection makefile for:	webkit
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	webkit
PORTVERSION=	26843
CATEGORIES=	www gnome
MASTER_SITES=	LOCAL/ahze
DISTNAME=	WebKit-r${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An opensource browser engine

LIB_DEPENDS=	icutu.36:${PORTSDIR}/devel/icu \
		curl.4:${PORTSDIR}/ftp/curl \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_PERL5=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build
USE_GNOME=	gtk20 libxml2
USE_BISON=	yes
INSTALL_WRKSRC=	${WRKSRC}/WebKitBuild/Release
BUILD_SCRIPT=	WebKitTools/Scripts/build-webkit
USE_LDCONFIG=	yes

do-build:
	@(cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${PERL5} ${BUILD_SCRIPT} --gtk --qmake=${QMAKE} \
	--qmakearg=WEBKIT_INC_DIR=${PREFIX}/include/WebKit --qmakearg=WEBKIT_LIB_DIR=${PREFIX}/lib)

pre-install:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${INSTALL_WRKSRC}/WebCore/Makefile
	@${MKDIR} ${INSTALL_WRKSRC}/libdata
	@${CP} -Rf ${INSTALL_WRKSRC}/lib/pkgconfig ${INSTALL_WRKSRC}/libdata/
#	@${REINPLACE_CMD} -e 's|/lib|$${prefix}/lib|; s|/include|$${prefix}/include|' \
#		${INSTALL_WRKSRC}/libdata/pkgconfig/WebKitGtk.pc

do-install:
	@(cd ${INSTALL_WRKSRC} && ${MAKE} install INSTALL_ROOT=${PREFIX})

.include <bsd.port.mk>
