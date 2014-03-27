# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	dbus
PORTVERSION=	1.1.1
CATEGORIES=	devel gnome python
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX=	py
PKGNAMESUFFIX=	-common
DISTNAME=	dbus-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common files for the Python bindings for the D-BUS messaging system

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gettext pathfix pkgconfig gmake
USE_PYTHON=	2
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--disable-api-docs

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=HTMLDOCS
HTMLDOCS_DESC=	build html documentation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTMLDOCS}
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
PLIST_SUB+=	HTML=""
.else
CONFIGURE_ARGS+=--disable-html-docs
PLIST_SUB+=	HTML="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|HEADERS install-dist_docDATA|HEADERS|g ; \
		s|PYTHON install-nodist_docDATA|PYTHON|g' \
			${WRKSRC}/Makefile.in
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/dbus-1.0/dbus/
	${INSTALL_DATA} ${WRKSRC}/include/dbus-python.h \
		${STAGEDIR}${PREFIX}/include/dbus-1.0/dbus/dbus-python.h
	${INSTALL_DATA} ${WRKSRC}/dbus-python.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/dbus-python.pc

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
