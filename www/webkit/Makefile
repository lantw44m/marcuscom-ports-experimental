# New ports collection makefile for:	webkit
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-experimental/www/webkit/Makefile,v 1.3 2007/10/22 01:19:39 ahze Exp $

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
USE_GNOME=	libxml2
USE_BISON=	build
INSTALL_WRKSRC=	${WRKSRC}/WebKitBuild/Release
BUILD_SCRIPT=	WebKitTools/Scripts/build-webkit
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WEBKIT_SLAVE) && ${WEBKIT_SLAVE}=="qt4"
QT_COMPONENTS+=	gui xml network
WEBKIT_GUI=	qt
.else
USE_GNOME+=	gtk20
WEBKIT_GUI=	gtk
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Linux i686|${OPSYS} ${ARCH}|' \
		${WRKSRC}/WebKit/gtk/WebCoreSupport/FrameLoaderClientGtk.cpp
	@${REINPLACE_CMD} -e 's|Intel; Linux;|${ARCH}; ${OPSYS};|' \
		${WRKSRC}/WebKit/qt/Api/qwebnetworkinterface.cpp

do-build:
	@(cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${PERL5} ${BUILD_SCRIPT} --${WEBKIT_GUI} --qmake=${QMAKE} \
	--qmakearg=WEBKIT_INC_DIR=${PREFIX}/include/WebKit --qmakearg=WEBKIT_LIB_DIR=${PREFIX}/lib)

pre-install:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${INSTALL_WRKSRC}/WebCore/Makefile
	@${MKDIR} ${INSTALL_WRKSRC}/libdata
	@${CP} -Rf ${INSTALL_WRKSRC}/lib/pkgconfig ${INSTALL_WRKSRC}/libdata/

do-install:
	@(cd ${INSTALL_WRKSRC} && ${MAKE} install)

.include <bsd.port.post.mk>
